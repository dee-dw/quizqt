/**
 * libquizqtbase - Part of quizqt
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

#ifndef QUIZPLAYER_HH
#define QUIZPLAYER_HH

#include <QString>

/**
 * Quiz player with name and points.
 */
class QuizPlayer
{
  public:
    /**
     * Constructor.
     * 
     * @param name Player name.
     */
    QuizPlayer( const QString& name );

    /**
     * @return name of player
     */
    const QString& getName() const;

    /**
     * @return points for answering correctly
     */
    int getPoints() const;

    /**
     * Adding (or subtracting) points.
     *
     * @param points Points, may be negative.
     */
    void addPoints( const int points );

  private:
    /**
     * Player name.
     */
    QString mName;
    
    /**
     * Points.
     */
    int mPoints;
};

// return name of player
inline
const QString& QuizPlayer::getName() const
{
    return mName;
}

// return points for answering correctly
inline
int QuizPlayer::getPoints() const
{
    return mPoints;
}

// Adding (or subtracting) points.
inline
void QuizPlayer::addPoints( const int points )
{
    mPoints += points;
}

#endif
