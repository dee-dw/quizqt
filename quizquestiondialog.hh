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

#ifndef QUIZQUESTIONDIALOG_HH
#define QUIZQUESTIONDIALOG_HH

#include "quizcategory.hh"
#include "quizentry.hh"
#include "quizplayer.hh"

#include <QDialog>

// Forward declarations.
class QLabel;
class QuizPlayer;

/**
 * Dialog for showing single question.
 */
class QuizQuestionDialog : public QDialog
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizQuestionDialog( const QuizCategory& category,
                        const QuizEntry& entry,
                        QList<QuizPlayer>& players,
                        QWidget* parent = 0 );

  signals:
    void showWidget(int);

  private slots:
    
    /**
     * Show the answer to a question.
     * 
     * @param show If true, show the answer, else hide it.
     */
    void showAnswer(bool show);
                     
  private:
    /**
     * Pointer to Label with answer that should be shown later.
     */
    QLabel* mAnswerLabelP;
    
    /**
     * Button for showing the answer or ending the round.
     */
    QPushButton* mShowButtonP;
};

#endif
