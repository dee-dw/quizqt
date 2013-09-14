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

#ifndef QUIZPLAYERBUTTON_HH
#define QUIZPLAYERBUTTON_HH

#include "quizplayer.hh"

#include <QPushButton>

/**
 * Special button for adding/subtracting points to some player.
 */
class QuizPlayerButton : public QPushButton
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizPlayerButton( QuizPlayer& player,
                      const int points,
                      QWidget* parent = 0 );

  private slots:
    /**
     * Add or subtract points for player.
     * 
     * @param add If true than add points, else subtract it.
     */
    void addPoints( bool add );
    
  private:
    /**
     * Player
     */
    QuizPlayer& mPlayer;
    
   /**
    * Points that could be earned.
    */
   const int mPoints;
};

#endif
