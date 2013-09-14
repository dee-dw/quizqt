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

#include "quizbutton.hh"
#include "quizentry.hh"

QuizButton::QuizButton( const int column, const int row, QuizEntry* entryP, QWidget* parent )
: QPushButton(parent), mColumn(column), mRow(row), mEntryP(entryP)
{
    // Groessere Schrift einstellen
    QFont aFont = font();
    aFont.setPointSize( 3*aFont.pointSize() );
    setFont( aFont );

    setText( QString("%1").arg(mEntryP->points()) );
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    connect(this, SIGNAL(clicked()), this, SLOT(setClickedSignal()));
}

void QuizButton::setClickedSignal()
{
    emit clicked(mColumn,mRow,mEntryP);
}
