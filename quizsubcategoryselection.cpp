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

#include "quizsubcategoryselection.hh"

QuizSubCategorySelection::QuizSubCategorySelection(
                              const QMap<QString, QStringList>& subCategoryMap,
                              QWidget* parent )
: QComboBox(parent), mSubCategoryMap(subCategoryMap)
{
    setMinimumWidth(200);
    setEnabled(false);
}

// Set new categories for selection.
void QuizSubCategorySelection::setCategories( const QStringList& categories )
{
    if ( categories.isEmpty() )
    {
        clear();
        setEnabled(false);
    }
    else
    {
        clear();
        addItem(tr("Random"));
        addItems(categories);
        setEnabled(true);
    }
}

// Sets a new category and shows the correct list of subcategories.
void QuizSubCategorySelection::setNewCategory( const QString& category )
{
    setCategories(mSubCategoryMap[category]);
}
