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

#ifndef QUIZSUBCATEGORYSELECTION_HH
#define QUIZSUBCATEGORYSELECTION_HH

#include <QComboBox>

// Forward declarations
class QStringList;
class QWidget;

/**
 * Some special box for selecting a new subcategory.
 */
class QuizSubCategorySelection : public QComboBox
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizSubCategorySelection( const QMap<QString, QStringList>& subCategoryMap,
                              QWidget* parent = 0 );

  public slots:
    /**
     * Sets a new category and shows the correct list of subcategories.
     * 
     * @param category New main category.
     */
    void setNewCategory( const QString& category );

  private:
    /**
     * Set new subcategories for selection.
     * 
     * @param categories List of subcategories.
     */
    void setCategories( const QStringList& categories );
    
  private:
    /**
     * Mapping of categories to subcategories
     */
    const QMap<QString, QStringList>& mSubCategoryMap;
};

#endif
