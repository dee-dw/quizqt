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

#ifndef QUIZDATABASE_HH
#define QUIZDATABASE_HH

#include "quizcategory.hh"
#include "quizentry.hh"

#include <QList>
#include <QMap>
#include <QStringList>

// Forward declarations
class QString;

/**
 * Database for the quiz.
 * 
 * This is not a real database. Just a bunch of members to access
 * the  information from the csv file.
 */
class QuizDatabase
{
  public:
    /**
     * Loads the questions from csv file and store it in the database.
     * 
     * @param fileName Filename for the csv file
     * @return true if file could be opened and all data extracted,
     * else false
     */
    bool load( const QString& fileName );
    
    /**
     * @return list of categories
     */
    const QStringList& getCategories() const;
    
    /**
     * @param category The category the subcategories should be get from
     * @return list of subcategories for one category
     */
    const QStringList getSubcategories( const QString& category ) const;
    
    /**
     * @return the mappring from categories to subcategories.
     */
    const QMap<QString, QStringList>& getSubcategoryMap() const;

    /**
     * Try to select the entries for the quiz.
     * 
     * For each category will be checked if there are enough questions
     * left. If so the selected entries will be marked as selected and
     * returned in the list. If not no entry will be selected.
     * 
     * @param categories List with category and subcategory
     * @param List with pointers to entries for each of the point values.
     * @return true if everything went fine or false if there was an error.
     */
    bool selectEntries( const QList<QuizCategory>& categories,
                        QList<QuizEntryPointers>& entries );

    /**
     * Add unused entries from the list.
     * 
     * This will add the entries that were not used in a quiz after
     * selecting them (see selectEntries) back to the lists.
     * 
     * @param entries List with pointers to entries for each of the point values.
     * @return true if everything went fine or false if there was an error.
     */
    bool addUnusedEntries( QList<QuizEntryPointers>& entries );

  private:
  
    /**
     * Reads a single semicolon separated line.
     *
     * @param entries List with entries the new entry should be attached to.
     * @param line Input line, separated by semicolons 
     * @return true if the lines has the right format and could be processed,
     * else false
     */
    bool readCsvLine( QList<QuizEntry>& entries, const QString& line );
    
    /**
     * Set new database and create some meta information.
     * 
     * @param entries List with new entries
     * @return true if all data could be set
     */
    bool setData( const QList<QuizEntry>& entries );
    
    /**
     * Return the array index for a point value.
     * 
     * @param points Must be one of 100, 200, 300 or 400.
     * @return Corresponding index 0, 1, 2 or 3.
     */
    int getPointIndex( const int points ) const;

    /**
     * add some entry pointer to the lists
     * 
     * @param Pointer to the entry that should be added
     * @return true if entry could be added to all lists, else false
     */
    bool addEntryPtr( QuizEntry* entryP );

    /**
     * remove some entry pointer from all lists
     * 
     * @param Pointer to the entry that should be removed
     * @return true if entry could be removed from all lists, else false
     */
    bool removeEntryPtr( QuizEntry* entryP );

    /**
     * Get question block for quiz.
     * 
     * This is for random questions.
     */
    bool getQuizEntryPointers( QuizEntryPointers& entryPointers );

    /**
     * Get question block for quiz.
     * 
     * This is for random questions in a specific category.
     */
    bool getQuizEntryPointers( QuizEntryPointers& entryPointers,
                               const QString& category );


    /**
     * Get question block for quiz.
     * 
     * This is for questions with specific category and subcategory
     */
    bool getQuizEntryPointers( QuizEntryPointers& entryPointers,
                               const QString& category,
                               const QString& subcategory );


    /**
     * Check if there is at least one question block left.
     * 
     * This is for random questions.
     */
    bool isOneQuestionBlockLeft() const;

    /**
     * Check if there is at least one question block left.
     * 
     * This is for random questions in a specific category.
     */
    bool isOneQuestionBlockLeft( const QString& category ) const;

    /**
     * Check if there is at least one question block left.
     * 
     * This is for questions with specific category and subcategory
     */
    bool isOneQuestionBlockLeft( const QString& category,
                                 const QString& subcategory ) const;


  private:
    /**
     * List of quiz entries.
     */
    QList<QuizEntry> mQuizEntries;

    /**
     * List of all categories.
     */
    QStringList mCategories;

    /**
     * Mapping of categories to subcategories
     */
    QMap<QString, QStringList> mSubCategoryMap;
    
    /**
     * We will store an array with four mappings for each of
     * the four possible points that can be given.
     */
    QList<QuizEntry*> mEntryMap[QuizEntry::numQuestionsPerCategory];
    
    /**
     * Mapping of a category to the corresponding entry.
     * 
     * We will store an array with four mappings for each of
     * the four possible points that can be given.
     */
    QMap<QString, QList<QuizEntry*> > mCategoryEntryMap[QuizEntry::numQuestionsPerCategory];
    
    /**
     * Mapping of a subcategory to the corresponding entry.
     * 
     * We will store an array with four mappings for each of
     * the four possible points that can be given.
     */
    QMap<QString, QList<QuizEntry*> > mSubCategoryEntryMap[QuizEntry::numQuestionsPerCategory];
};

// return list of categories
inline
const QStringList& QuizDatabase::getCategories() const
{
    return mCategories;
}

// return list of subcategories for one category
inline
const QStringList QuizDatabase::getSubcategories( const QString& category ) const
{
    return mSubCategoryMap[category];
}

// return the mappring from categories to subcategories.
inline
const QMap<QString, QStringList>& QuizDatabase::getSubcategoryMap() const
{
    return mSubCategoryMap;
}

#endif
