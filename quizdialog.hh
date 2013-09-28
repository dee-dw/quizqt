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

#ifndef QUIZDIALOG_HH
#define QUIZDIALOG_HH

#include "quizcategory.hh"
#include "quizentry.hh"
#include "quizplayer.hh"

#include <QDialog>
#include <QList>
#include <QString>
#include <QVector>

// Forward declarations.
class QuizButton;
class QCloseEvent;
class QLabel;

/**
 * Dialog for showing questions and counting points.
 */
class QuizDialog : public QDialog
{
    Q_OBJECT

  public:
    /**
     * Default Constructor.
     * 
     * This creates the whole dialog window with all menus and elements.
     */
    QuizDialog( const QList<QuizCategory>& categories,
                const QList<QuizEntryPointers>& entries,
                const QList<QuizPlayer>& players );

  private slots:
    /**
     * Show the question under this coordinates.
     */
    void showQuestion(const int column, const int row, QuizEntry* entryP);

  protected:
    /**
     * Close dialog.
     */
    virtual void closeEvent(QCloseEvent *event);

  private:
    /**
     * Field with quiz buttons.
     */
    QVector<QVector<QuizButton*> > mButtons;

    /**
     * List for showing players points.
     */
    QVector<QLabel*> mPointsLabels;
    
    /**
     * Number of questions per category.
     */
    int mNumQuestions;
    
    /**
     * List of categories.
     */
    QList<QuizCategory> mCategories;
    
    /**
     * List of players.
     */
    QList<QuizPlayer> mPlayers;
};

#endif
