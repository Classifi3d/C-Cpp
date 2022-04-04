using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Anagrama
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = "plasmapheresis";
            string y = "anagramaCuvantuluiInitial";
            int[] alfabetContorA = new int[26];//sau cate litere sunt in alfabet :)))
            int[] alfabetContorB = new int[26];
            for (int i = 0; i < 26; i++)
            {
                alfabetContorA[i] = 0;
                alfabetContorB[i] = 0;
            }

            string alfabet = "abcdefghijklmnopqrstuvwxyz";
            
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (s[i] == alfabet[j])
                    {
                        alfabetContorA[j]++;
                    }
                }
            }

            for (int i = 0; i < y.Length; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (y[i] == alfabet[j])
                    {
                        alfabetContorB[j]++;
                    }
                }
            }

            int okAnagrama = 1;
            for (int i = 0; i < 26; i++)
            {
                if (alfabetContorA[i] != alfabetContorB[i])
                {
                    okAnagrama = 0;
                }
            }
            if (okAnagrama == 1) {//E anagrama
                Console.WriteLine("E anagrama");
            }
            else{ //Nu e anagrama
                Console.WriteLine("Nu e anagrama");
            }


            
            Console.ReadLine();
        }
    }
}
