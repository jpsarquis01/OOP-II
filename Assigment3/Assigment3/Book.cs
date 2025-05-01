using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    public class Book : Product
    {
        private string _author;
        private string _genre;
        private int _publicationYear;
        private string _title;

        public Book(string title, string author, string genre, int publicationYear)
        {
            _title = title;
            _author = author;
            _genre = genre;
            _publicationYear = publicationYear;
        }

        public override void DisplayInfo()
        {
            Console.WriteLine("---------------------------");
            Console.WriteLine($"Title: {_title}");
            Console.WriteLine($"Author: {_author}");
            Console.WriteLine($"Genre: {_genre}");
            Console.WriteLine($"Publication Year: {_publicationYear}");
            Console.WriteLine("---------------------------");
        }

        public int IsModern()
        {
            int modernYear = 2015;

            if (_publicationYear >= modernYear)
            {
                Console.WriteLine($"The book {_title} is modern.");
                return 1;
            }
            else
            {
                Console.WriteLine($"The book {_title} is not modern.");
                return 0;
            }
        }
    }
}
