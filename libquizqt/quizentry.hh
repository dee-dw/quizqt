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

#ifndef QUIZENTRY_HH
#define QUIZENTRY_HH

#include <QString>
#include <QStringList>

/**
 * Single quiz entry.
 */
class QuizEntry
{
  public:
    /**
     * This constructor sets all necessary values.
     * 
     * You can ask with isValid() if everything is correctly set.
     * 
     * @param categories The categories are mandatory. There should be at
     * least one in the list.
     * @param subcategory The subcategory is optional and may be empty.
     * @param question The question is mandatory.
     * @param answer The answer is mandatory.
     * @param points The points for giving the right answer are mandatory.
     * The value can be one of 100, 200, 300 or 400.
     */
    QuizEntry( const QStringList& categories,
               const QString& subcategory,
               const QString& question, 
               const QString& answer,
               const int points ); 
    
    /**
     * @return list with all categories
     */
    const QStringList& categories() const;
    
    /**
     * @return subcategory
     */
    const QString& subcategory() const;

    /**
     * @return question
     */
    const QString& question() const;

    /**
     * @return answer
     */
    const QString& answer() const;

    /**
     * @return points for answering correctly
     */
    int points() const;
    
    /**
     * Check if the entry is valid.
     * 
     * That means that category, question, answer and points are set.
     * 
     * @return true if the entry is valid
     */
    bool isValid() const;
    
    /**
     * Check if question was asked before.
     * 
     * @return true if entry was used before for asking a question
     */
    bool isUsed() const;

    /**
     * Mark entry as used.
     */
    void setUsed();
    
    /**
     * Mark or unmark entry as selected for a quiz.
     */
    void setSelected( const bool val );

    /**
     * Check if question was selected for a quiz.
     * 
     * @return true if selected before
     */
    bool isSelected() const;

    /**
     * The number must equal the number of different point values
     * in the entries.
     */
    static const int numQuestionsPerCategory = 4;

  private:
    /**
     * List of categories
     */
    QStringList mCategories;
    
    /**
     * An optional subcategory.
     */
    QString mSubCategory;
    
    /**
     * The question.
     */
    QString mQuestion;
    
    /**
     * The answer.
     */
    QString mAnswer;
    
    /**
     * Points for giving the right answer.
     */
    int mPoints;
    
    /**
     * Flag if this question was asked before.
     */
    bool mUsed;
    
    /**
     * Flag that this question was selected for a quiz.
     * 
     * That doesn't mean that it was asked. The flag will
     * be reset if the entry wasn't used.
     */
    bool mSelected;
    
    /**
     * Flag if this entry is valid.
     */
    bool mValid;
};

/**
 * Simples struct for holding the entry pointers.
 */
struct QuizEntryPointers
{
    /**
     * Default constructor.
     */
    QuizEntryPointers();
    
    QuizEntry* entriesP[QuizEntry::numQuestionsPerCategory];
};

// return list with all categories
inline
const QStringList& QuizEntry::categories() const
{
    return mCategories;
}

// return subcategory
inline
const QString& QuizEntry::subcategory() const
{
    return mSubCategory;
}

// return question
inline
const QString& QuizEntry::question() const
{
    return mQuestion;
}

// return answer
inline
const QString& QuizEntry::answer() const
{
    return mAnswer;
}

// return points for answering correctly
inline
int QuizEntry::points() const
{
    return mPoints;
}

// Check if the entry is valid.
inline
bool QuizEntry::isValid() const
{
    return mValid;
}
    
// Check if question was asked before.
inline
bool QuizEntry::isUsed() const
{
    return mUsed;
}

// Mark entry as used.
inline
void QuizEntry::setUsed()
{
    mUsed = true;
}

// Mark or unmark entry as selected for a quiz.
inline
void QuizEntry::setSelected( const bool val )
{
    mSelected = val;
}

// Check if question was selected for a quiz.
inline
bool QuizEntry::isSelected() const
{
    return mSelected;
}

#endif
