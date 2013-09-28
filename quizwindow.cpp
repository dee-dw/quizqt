/**
 * quizqt - Quiz-App written in Qt
 * 
 * Copyright (C) 2013 Dominik Wagenfuehr <dee@deesaster.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quizwindow.hh"
#include "quizcategory.hh"
#include "quizcategoryselection.hh"
#include "quizdialog.hh"
#include "quizerror.hh"
#include "quizerrormessagebox.hh"
#include "quizsubcategoryselection.hh"
#include "quizplayer.hh"

#include <QtGui>

// Default constructor.
QuizWindow::QuizWindow()
{
    // Group the categories.
    QGroupBox* categoryGroupBoxP = new QGroupBox(tr("Choose categories"));

    QHBoxLayout *categoriesLayoutP = new QHBoxLayout;
    for ( int ii = 0; ii < mMaxNumberCategories; ii++ )
    {
        // Label above combo box
        QLabel* categoryLabelP = new QLabel( QString(tr("Category %1")).arg(ii+1) );
        categoryLabelP->setAlignment(Qt::AlignCenter);

        // The default category is random.
        mCategorySelectionP[ii] = new QuizCategorySelection;
        
        // The default category is random, so there is no subcategory.
        mSubCategorySelectionP[ii] =
                  new QuizSubCategorySelection( mDataBase.getSubcategoryMap() );
        
        connect( mCategorySelectionP[ii], SIGNAL(currentIndexChanged(const QString&)),
                 mSubCategorySelectionP[ii], SLOT(setNewCategory(const QString&)) );
        
        QVBoxLayout *categoryLayoutP = new QVBoxLayout;
        categoryLayoutP->addWidget(categoryLabelP);
        categoryLayoutP->addWidget(mCategorySelectionP[ii]);
        categoryLayoutP->addWidget(mSubCategorySelectionP[ii]);

        categoriesLayoutP->addLayout(categoryLayoutP);
    }

    categoryGroupBoxP->setLayout(categoriesLayoutP);
    categoryGroupBoxP->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );

    // Group the players.
    QGroupBox* playerGroupBoxP = new QGroupBox(tr("Set name of players"));

    QVBoxLayout *playerNamesLayoutP = new QVBoxLayout;
    for ( int ii = 0; ii < mMaxNumberPlayers; ii++ )
    {
        QLabel* playerLabelP = new QLabel( QString(tr("Player %1")).arg(ii+1) );
        
        mPlayerLineP[ii] = new QLineEdit( QString(tr("Player %1")).arg(ii+1) );

        QHBoxLayout *playerLayoutP = new QHBoxLayout;
        playerLayoutP->addWidget(playerLabelP);
        playerLayoutP->addWidget(mPlayerLineP[ii]);

        playerNamesLayoutP->addLayout(playerLayoutP);
    }

    playerGroupBoxP->setLayout(playerNamesLayoutP);
    playerGroupBoxP->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
    
    // Group the controls.
    QGroupBox* controlGroupBoxP = new QGroupBox(tr("Control"));

    mLoadButtonP = new QPushButton(tr("&Load questions"));
    connect(mLoadButtonP, SIGNAL(clicked()), this, SLOT(loadQuestions()));
    
    mStartButtonP = new QPushButton(tr("&Start quiz"));
    connect(mStartButtonP, SIGNAL(clicked()), this, SLOT(startQuiz()));

    QHBoxLayout *controlLayoutP = new QHBoxLayout;
    controlLayoutP->addWidget(mLoadButtonP); 
    controlLayoutP->addWidget(mStartButtonP); 
    controlLayoutP->addStretch(); 

    controlGroupBoxP->setLayout(controlLayoutP);
    controlGroupBoxP->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );

    QVBoxLayout *widgetLayoutP = new QVBoxLayout;
    widgetLayoutP->addWidget(categoryGroupBoxP);
    widgetLayoutP->addWidget(playerGroupBoxP);
    widgetLayoutP->addWidget(controlGroupBoxP);

    QWidget* widgetP = new QWidget;
    widgetP->setLayout(widgetLayoutP);
    setCentralWidget(widgetP);
    
    setWindowTitle( tr("Ubucon-Quiz 2013") );
}

// Load questions.
void QuizWindow::loadQuestions()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open question csv file"), QString(), tr("CSV Files (*.csv)"));
    
    if ( !fileName.isEmpty() )
    {
        QuizError error = mDataBase.load(fileName);
        
        if ( error.noError() )
        {
            // Update all combo boxes
            for ( int ii = 0; ii < mMaxNumberCategories; ii++ )
            {
                mCategorySelectionP[ii]->setCategories(mDataBase.getCategories());
            }
        }
        else
        {
            QuizErrorMessageBox::show( this, error );
        }
    }
}

// Start quiz.
void QuizWindow::startQuiz()
{
    // First we must get the categories that has been choosen.
    QList<QuizCategory> selectedCategories;
    for ( int ii = 0; ii < mMaxNumberCategories; ii++ )
    {
        selectedCategories.append(
            QuizCategory( mCategorySelectionP[ii]->currentText(), mSubCategorySelectionP[ii]->currentText(), ii ) );
    }
    
    // We will give this category selection and will get back
    // the list of entries that we should use.
    // For each entry in the resulting list we will have four values for
    // the different points.
    // This will not mark the entries as used!
    QList<QuizEntryPointers> selectedEntries;
    QuizError error = mDataBase.selectEntries( selectedCategories, selectedEntries );
    
    if ( error.noError() )
    {
        // get player names
        QList<QuizPlayer> players;
        for ( int ii = 0; ii < mMaxNumberPlayers; ii++ )
        {
            players.append( QuizPlayer( mPlayerLineP[ii]->text() ) );
        }
        
        // show dialog for quiz
        QuizDialog dialog( selectedCategories, selectedEntries, players );
        dialog.exec();
        
        // Readd all unused questions if there were any
        mDataBase.addUnusedEntries( selectedEntries );
    }
    else
    {
        QuizErrorMessageBox::show( this, error );
    }
}
