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

#ifndef QUIZBUTTON_HH
#define QUIZBUTTON_HH

#include "quizentry.hh"

#include <QPushButton>

// Forward declarations
class QuizEntry;

/**
 * Some special button for associating a question with it.
 */
class QuizButton : public QPushButton
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizButton( const int column, const int row,
                QuizEntry* entryP, QWidget* parent = 0 );

  signals:
    void clicked(const int, const int, QuizEntry*);

  private slots:
    /**
     * Set signal with id of button.
     */
    void setClickedSignal();

  private:
    /**
     * Column number of button location
     */
    int mColumn;
    
    /**
     * Row number of button location.
     */
    int mRow;
    
    /**
     * Pointer to the quiz entry.
     */
    QuizEntry* mEntryP;
};

#endif
