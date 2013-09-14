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

#ifndef QUIZCATEGORYSELECTION_HH
#define QUIZCATEGORYSELECTION_HH

#include <QComboBox>

// Forward declarations
class QStringList;
class QWidget;

/**
 * Some special box for selecting a new category.
 */
class QuizCategorySelection : public QComboBox
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizCategorySelection( QWidget* parent = 0 );
    
    /**
     * Set new categories for selection.
     * 
     * @param categories List of categories.
     */
    void setCategories( const QStringList& categories );
};

#endif
