// PrettyTable.h
// SPDX-FileCopyrightText: 2015-2026 David Rabkin
// SPDX-License-Identifier: 0BSD

#ifndef PRETTY_TABLE_H_
#define PRETTY_TABLE_H_

#include <list>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>
#include "AlphaNum.h"
//#define PRETTY_TABLE_DEBUG 1
#ifdef PRETTY_TABLE_DEBUG
  #include <iostream>
#endif

// Takes a reference to an array and returns a reference to a char array of
// the same length. It has no definition and is never called. The sizeof
// operator evaluates its return type at compile time, so ARRAYSIZE yields
// the element count and rejects pointers.
template <typename T, size_t size>
char (&arraysize_helper(T (&)[size]))[size];

#define ARRAYSIZE(arr) (sizeof(arraysize_helper(arr)))
#define ARRAYEND(arr) ((arr) + ARRAYSIZE(arr))

// Disables the copy constructor and the copy assignment operator. A class
// that derives from CNonCopyable becomes non-copyable, since both members
// stay private. Usage example:
// class CFooBar : public CNonCopyable {};
class CNonCopyable
{
 protected:
  CNonCopyable()
  {}
  ~CNonCopyable()
  {}

 private:
  CNonCopyable(const CNonCopyable&);
  void operator=(const CNonCopyable&);
};

// Advances an enum value to the next enumerator and wraps from last back to
// first. It returns the updated value.
template <typename Enum>
Enum& enum_increment(Enum& value, const Enum& first, const Enum& last)
{ return value = (value == last) ? first : static_cast<Enum>(value + 1); }

// Marks an unused column as the default template parameter of CPrettyTable.
// Its size of three bytes matches no native type, so AddCell detects it.
struct PrettyTableStubType
{
  char buf[3];
};

// Selects the direction of CPrettyTable::Sort.
enum ePrettyTableSortOrder
{
  ePTSO_Ascending,
  ePTSO_Descending
};

// Lets AddCell compile for the stub type. It has no definition and is never
// called.
std::ostream& operator<<(std::ostream& os, const PrettyTableStubType&);

// Formats and prints string and numeric data as a table. Each template
// parameter is the type of one column, up to 20 columns. The template
// calculates column widths after all rows are known. Example:
//
// CPrettyTable<int, const char*, double> tbl("num", "name", "score");
// for (int i = 0; i < 5; ++i)
//   tbl.Add(i + 1, "FooBar", 2.5 * (i + 1));
// tbl.SetCaption("FooBar");
// tbl.Dump(std::cerr);
//
// The example prints the following output to the standard error stream:
// +-----+[ FooBar ]------+
// | num | name   | score |
// +-----+--------+-------+
// |   1 | FooBar |   2.5 |
// |   2 | FooBar |     5 |
// |   3 | FooBar |   7.5 |
// |   4 | FooBar |    10 |
// |   5 | FooBar |  12.5 |
// +-----+--------+-------+
template<typename T01=PrettyTableStubType,
         typename T02=PrettyTableStubType,
         typename T03=PrettyTableStubType,
         typename T04=PrettyTableStubType,
         typename T05=PrettyTableStubType,
         typename T06=PrettyTableStubType,
         typename T07=PrettyTableStubType,
         typename T08=PrettyTableStubType,
         typename T09=PrettyTableStubType,
         typename T10=PrettyTableStubType,
         typename T11=PrettyTableStubType,
         typename T12=PrettyTableStubType,
         typename T13=PrettyTableStubType,
         typename T14=PrettyTableStubType,
         typename T15=PrettyTableStubType,
         typename T16=PrettyTableStubType,
         typename T17=PrettyTableStubType,
         typename T18=PrettyTableStubType,
         typename T19=PrettyTableStubType,
         typename T20=PrettyTableStubType>
class CPrettyTable : CNonCopyable
{
 public:
  // Creates a table without a header row.
  CPrettyTable() : m_has_header(false) {}

  // Creates a table with a header row. Each argument is a column title.
  // The first NULL argument ends the list.
  CPrettyTable(const char* p01,
               const char* p02 = NULL,
               const char* p03 = NULL,
               const char* p04 = NULL,
               const char* p05 = NULL,
               const char* p06 = NULL,
               const char* p07 = NULL,
               const char* p08 = NULL,
               const char* p09 = NULL,
               const char* p10 = NULL,
               const char* p11 = NULL,
               const char* p12 = NULL,
               const char* p13 = NULL,
               const char* p14 = NULL,
               const char* p15 = NULL,
               const char* p16 = NULL,
               const char* p17 = NULL,
               const char* p18 = NULL,
               const char* p19 = NULL,
               const char* p20 = NULL) : m_has_header(true)
  {
    const char* names[] = {
        p01, p02, p03, p04, p05, p06, p07, p08, p09, p10,
        p11, p12, p13, p14, p15, p16, p17, p18, p19, p20
    };
    std::vector<Val> row;
    row.reserve(ARRAYSIZE(names));
    for (const char** name = names;
         name != ARRAYEND(names) && NULL != *name;
         ++name)
      row.push_back(std::make_pair(*name, false));
    m_db.push_back(row);
  }

  // Sets the caption that the top border embeds. NULL clears it.
  void SetCaption(const char* s) { m_caption = (NULL != s) ? s : ""; }

  // Appends a row with one value per column. Omitted values leave the
  // trailing cells empty.
  void Add(const T01& p01 = PrettyTableStubType(),
           const T02& p02 = PrettyTableStubType(),
           const T03& p03 = PrettyTableStubType(),
           const T04& p04 = PrettyTableStubType(),
           const T05& p05 = PrettyTableStubType(),
           const T06& p06 = PrettyTableStubType(),
           const T07& p07 = PrettyTableStubType(),
           const T08& p08 = PrettyTableStubType(),
           const T09& p09 = PrettyTableStubType(),
           const T10& p10 = PrettyTableStubType(),
           const T11& p11 = PrettyTableStubType(),
           const T12& p12 = PrettyTableStubType(),
           const T13& p13 = PrettyTableStubType(),
           const T14& p14 = PrettyTableStubType(),
           const T15& p15 = PrettyTableStubType(),
           const T16& p16 = PrettyTableStubType(),
           const T17& p17 = PrettyTableStubType(),
           const T18& p18 = PrettyTableStubType(),
           const T19& p19 = PrettyTableStubType(),
           const T20& p20 = PrettyTableStubType())
  {
    std::vector<Val> row;
    row.reserve(20);
    AddCell(row, p01);
    AddCell(row, p02);
    AddCell(row, p03);
    AddCell(row, p04);
    AddCell(row, p05);
    AddCell(row, p06);
    AddCell(row, p07);
    AddCell(row, p08);
    AddCell(row, p09);
    AddCell(row, p10);
    AddCell(row, p11);
    AddCell(row, p12);
    AddCell(row, p13);
    AddCell(row, p14);
    AddCell(row, p15);
    AddCell(row, p16);
    AddCell(row, p17);
    AddCell(row, p18);
    AddCell(row, p19);
    AddCell(row, p20);
    m_db.push_back(row);
  }

  // Returns the number of data rows without the header row.
  unsigned int Size() const
  {
    if (IsEmpty())
      return 0;
    return m_db.size() - 1;
  }

  // Reports whether the table has no data rows.
  bool IsEmpty() const
  {
    if (m_db.empty())
      return true;
    if (m_has_header && 1 == m_db.size())
      return true;
    return false;
  }

  // Returns the printed table as a string.
  std::string Get() const
  {
    std::ostringstream buf;
    Dump(buf);
    return buf.str();
  }

  // Removes all data rows and keeps the header row.
  void Clear()
  {
    if (m_has_header)
      m_db.erase(++m_db.begin(), m_db.end());
    else
      m_db.clear();
  }

  // Prints the table to the stream. It measures the widest cell of each
  // column first. Then it prints the top border, which holds the caption if
  // one is set. The header row and its delimiter follow, then the data rows
  // and the bottom border. Every line starts with a newline.
  void Dump(std::ostream& out) const
  {
    if (m_db.empty())
      return;
    std::vector<unsigned int> lens;
    DB::const_iterator row;
    for (row = m_db.begin(); row != m_db.end(); ++row)
    {
      if (row->size() > lens.size())
        lens.insert(lens.end(), row->size() - lens.size(), 0);
      std::vector<Val>::const_iterator col;
      for (col = row->begin(); col != row->end(); ++col)
      {
        unsigned int pos = row->size() - std::distance(col, row->end());
        if (lens[pos] < col->first.length())
          lens[pos] = col->first.length();
      }
    }
    if (lens.empty())
      return;
    if (!m_caption.empty())
      PrintCaption(lens, out);
    else
      PrintDelimiter(lens, out);
    PrintRow(*m_db.begin(), lens, out);
    if (m_has_header)
      PrintDelimiter(lens, out);
    row = m_db.begin();
    for (++row; row != m_db.end(); ++row)
      PrintRow(*row, lens, out);
    PrintDelimiter(lens, out);
  }

  // Sorts the data rows by the zero-based column in the given order. The
  // header row stays on top. The alphanumeric comparison makes the operation
  // CPU-intensive on large tables.
  void Sort(unsigned int col, ePrettyTableSortOrder order = ePTSO_Ascending)
  {
    DB title;
    if (m_has_header)
      title.splice(title.begin(), m_db, m_db.begin());
    m_db.sort(RowCmp(col, order));
    if (m_has_header)
      m_db.splice(m_db.begin(), title, title.begin());
  }

 private:
  // Compares two rows by one column. It uses Dirk Jagdmann's alphanumeric
  // comparator for human-friendly ordering. A row without the column always
  // compares as less.
  class RowCmp
  {
   public:
    RowCmp(unsigned int c, ePrettyTableSortOrder o) : m_col(c), m_order(o) {}
    bool operator()(const std::vector<std::pair<std::string, bool> >& lhs,
                    const std::vector<std::pair<std::string, bool> >& rhs) const
    {
      if (m_col >= lhs.size() || m_col >= rhs.size())
        return true;
      int res = doj::alphanum_comp(lhs[m_col].first, rhs[m_col].first);
      return (ePTSO_Ascending == m_order) ? res < 0 : res >= 0;
    }

   private:
    unsigned int          m_col;
    ePrettyTableSortOrder m_order;
  };

  // Converts a value to a cell and appends it to the row. It skips the stub
  // type that marks an omitted argument. Numeric types report
  // is_specialized=true and become right-aligned. Other types, such as
  // strings, stay left-aligned.
  template<typename T>
  void AddCell(std::vector<std::pair<std::string, bool> >& row, const T& p)
  {
    if (sizeof(PrettyTableStubType) == sizeof(T))
      return;
    std::ostringstream buf;
    buf << p;
    row.push_back(std::make_pair(buf.str(),
                                 std::numeric_limits<T>::is_specialized));
  }

  // Prints one row on a new line and pads each cell to its column width.
  void PrintRow(std::list<std::vector<std::pair<std::string, bool> > >::const_reference row,
                 const std::vector<unsigned int>& lens,
                 std::ostream& out) const
  {
    out << std::endl << '|';
    std::vector<Val>::const_iterator col = row.begin();
    std::vector<unsigned int>::const_iterator len = lens.begin();
    for ( ; col != row.end() && len != lens.end(); ++col, ++len)
      out << " "
          << (col->second ? std::right : std::left)
          << std::setw(*len)
          << col->first << " |";
  }

  // Prints a border line on a new line.
  void PrintDelimiter(const std::vector<unsigned int>& lens,
                      std::ostream& out) const
  {
    out << std::endl << '+';
    std::vector<unsigned int>::const_iterator len;
    for (len = lens.begin(); len != lens.end(); ++len)
      out << std::string(*len + 2, '-') << '+';
  }

  // Embeds the caption into the top border, for example:
  // +----+-[ FooBar ]-------+
  // The table width counts each column, a three-character delimiter segment
  // per column, and the '+' on each side. A caption wider than the table
  // replaces the whole border. The missing width then goes to the columns,
  // and the first column takes the remainder. Otherwise the caption
  // replaces the middle of a regular border.
  void PrintCaption(std::vector<unsigned int>& lens,
                    std::ostream& out) const
  {
#ifdef PRETTY_TABLE_DEBUG
    std::cerr << "lens[]: ";
    std::copy(lens.begin(), lens.end(),
              std::ostream_iterator<unsigned int>(std::cerr, " "));
    std::cerr << '\n';
#endif
    const char del[] = { '-', '+', '-' };
    unsigned int dsz = ARRAYSIZE(del);
    std::ostringstream buf;
    buf << "-[ " << m_caption << " ]-";
    std::string caption = buf.str();
    unsigned int all =
      std::accumulate(lens.begin(), lens.end(), 2 + dsz * lens.size());
    if (caption.length() >= all - 2)
    {
      out << '+' << caption << '+';
      unsigned int gap = caption.length() - all + 2 + 1;
      if (gap >= lens.size())
      {
        unsigned int pad = gap / lens.size();
        unsigned int pa0 =
          (0 != (gap % lens.size())) ? pad + gap % lens.size() : pad;
        lens[0] += pa0;
        std::transform(++lens.begin(), lens.end(), ++lens.begin(),
                       std::bind2nd(std::plus<unsigned int>(), pad));
#ifdef PRETTY_TABLE_DEBUG
        std::cerr << '\n'
                  << "gap:" << gap
                  << ", pad:" << pad
                  << ", pa0:" << pa0 << "\n";
#endif
      }
      else
      {
        lens[0] += gap;
      }
      return;
    }
    std::stringstream bu2;
    PrintDelimiter(lens, bu2);
    std::string line = bu2.str();
    unsigned int gap = (all - caption.length()) / 2;
    out << std::string(line, 0, gap)
        << caption
        << std::string(line, gap+caption.length());
  }

  typedef std::pair<std::string, bool> Val;
  typedef std::vector<Val> Raw;
  typedef std::list<Raw> DB;

  DB m_db;
  bool m_has_header;
  std::string m_caption;
};

#ifdef PRETTY_TABLE_DEBUG
int main()
{
  CPrettyTable<int, const char*, double, const char*>
    tbl("num", "name", "score", "value");
  for (int j = 0; j < 20; ++j)
  {
    std::stringstream buf;
    buf << "foo-" << j << '-' << (char)'a' + j << "-bar-" << 20 - j;
    tbl.Add(j, buf.str().c_str(), j * 2.5, "looooooooooooong string");
  }
  tbl.Sort(1);
  std::cerr << "Sort ascending\n" << tbl.Get() << '\n';
  tbl.Sort(1, ePTSO_Descending);
  std::cerr << "Sort descending\n" << tbl.Get() << '\n';
  tbl.Clear();
  std::cerr << "Caption\n";
  tbl.Add(100, "short", 0, "long");
  for (int i = 0; i < 30; ++i)
  {
    std::stringstream buf;
    buf << i << ' ' << std::string(i, 'F');
    tbl.SetCaption(buf.str().c_str());
    std::cerr << tbl.Get() << '\n';
  }
  std::cerr << "Resource consumption\n";
  for (int k = 0; k < 20000; ++k)
  {
    tbl.Add(k, std::string(1000, '+').c_str(), 0, "looooooooooooong string");
  }
  tbl.Clear();
  std::cerr << tbl.Get() << "\nDone.\n";
  return 0;
}
#endif  //  PRETTY_TABLE_DEBUG

#endif  // PRETTY_TABLE_H_
