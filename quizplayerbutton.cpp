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

#include "quizplayerbutton.hh"

// Constructor.
QuizPlayerButton::QuizPlayerButton( QuizPlayer& player,
                                    const int points,
                                    QWidget* parent )
: QPushButton(parent), mPlayer(player), mPoints(points)
{
    setText( QString("%1: +%2").arg(mPlayer.getName()).arg(mPoints) );
    setCheckable(true);
    connect( this, SIGNAL(toggled(bool)), this, SLOT(addPoints(bool)) );
}

// Add or subtract points for player.
void QuizPlayerButton::addPoints( bool add )
{
    if ( add )
    {
        mPlayer.addPoints( mPoints );
        setText( QString("%1: -%2").arg(mPlayer.getName()).arg(mPoints) );
    }
    else
    {
        mPlayer.addPoints( -mPoints );
        setText( QString("%1: +%2").arg(mPlayer.getName()).arg(mPoints) );
    }
}
