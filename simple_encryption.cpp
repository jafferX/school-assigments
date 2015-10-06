Erik Leung
9/22/2016
program that asks for a txt file containing a string that is then either decryted or encryted. After that process is finished the new vector is outputed into a text file.
1.0v
input: information in a txt file is placed into a vector.
output: a vector containing the encrypted or decrypted string.


*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string>getDataForEncryption();
void printWordsFromVector(vector <string> d);
vector<string>doEndUsingRot(vector<string> g, int rot);
string endLetterUsingRot(string word, int Rot);
string dendLetterUsingRot(string word3,int Rot1);
vector<string>doDendUsingRot(vector<string>j1, int rot2);
vector<string>doEndUsingCrypto(vector<string> h3, string normalKey, string cryptogramKey);
string endLetterUsingCrypto(string word4, string key1, string key2);
string dendLetterUsingCrypto(string word8, string key01, string key02);
vector<string> doDendUsingCrypto(vector<string> h6, string normalKey1, string cryptogramKey1);
string getDataKey();
void outPutFile(vector <string> kaga);
string toLower(string word9);


 
int main ()
{
  vector <string> word1;
  vector <string> word2;
  cout << "This program will encrypt or decrypt a string using rotation or a cr  ytogram"<< endl;
  cout<<"-------------------------------------------------------------------"<<  endl;
  char choice;
  char secChoice;
  int rotation;
  word1 = getDataForEncryption(); //original.txt is put into word1
  cout<<"what do you want to do:"<<endl;
  do
    {
      cout<<"select R or r for Rotation, C or c for Cryptogram, or Q or q to Quit"<<endl;
      cin >> choice;
      cout<<endl;
      choice = tolower(choice);

      if(choice == 'r')
	{ 
	  do
	    {
	  cout<< "you have selected to use the rotation method"<<endl;
	  cout<< "enter E or e to encrypt or enter D or d to decrypt or Q or q to quit:";
	  cin >> secChoice;
	  secChoice = tolower(secChoice);
	      if (secChoice == 'e')
		{
		  cout<<"we will now encrypt the string"<<endl;
		  cout<<"enter the number you wish to  rotate string charactrs by"<<endl;
		  cin >> rotation;
		  word2 = doEndUsingRot(word1, rotation);
		  cout<<"----------------------------------------------------------------------------------"<<endl;
		  cout<<"encryption finished"<<endl;
		  cout<<"printing encrypted string"<<endl;
		  printWordsFromVector(word2);
		  outPutFile(word2);
		  cout<<"enter Q or q to quit or enter any key to return to earlier instruction"<<endl;
		  cin >> secChoice;
		  secChoice = tolower(secChoice);
		  //can decrypt without quitting program. don't hit q

		}
	      else if (secChoice =='d')
		{
		  cout<<"we will now decrypt the string"<<endl;
                  cout<<"enter the number you wish to  rotate string charactrs by"<<endl;
                  cin >> rotation;
		  word2 = doDendUsingRot(word2,rotation);
                  cout<<"----------------------------------------------------------------------------------"<<endl;
                  cout<<"decryption finished"<<endl;
                  cout<<"printing decrypted string"<<endl;
                  printWordsFromVector(word2);
                  outPutFile(word2);
                  cout<<"enter Q or q to quit or enter any key to return to earlier instruction"<<endl;
                  cin >> secChoice;
		  secChoice = tolower(secChoice);
		}
	      else if (secChoice =='q')
		{
		  cout<<"returning to earlier menu"<<endl;
		}
	    } while (secChoice != 'q');
	    }
	  else  if(choice == 'c')
	    {// must be entered in order of aKey then cKey.
	      cout<<"enter name of txt file containing string a to z"<<endl;
		string keyNormal = getDataKey(); //keyNormal contains normal 26 letter a to z key in txt file aKey.txt. aKey.txt: contains:abcdefghijklmnopqrst
		cout<<"enter name of txt file containing cryptogram key"<<endl;
		string cryptogram =   getDataKey();//cryptogram contains cryptogram key read in from cKey.txt

		do
		  {
		    cout<< "you have selected to use the crypotgram method"<<endl;
		    cout<< "enter E or e to encrypt or enter D or d to decrypt or Q or q to quit:";
		    cin >> secChoice;
		    secChoice = tolower(secChoice);
		    if (secChoice =='e')
		      {
			cout<<"we will now encrypt the string"<<endl;
			word2 = doEndUsingCrypto(word1,keyNormal, cryptogram);
			cout<<"----------------------------------------------------------------------------------"<<endl;
			cout<<"encryption finished"<<endl;
			cout<<"printing encrypted string"<<endl;
			printWordsFromVector(word2);
			outPutFile(word2);
			cout<<"enter Q or q to quit or enter any key to return to earlier instruction"<<endl;
			cin >> secChoice;
			secChoice = tolower(secChoice);
			//can decrypt without quitting program. don't hit q

		      }
		   else  if (secChoice == 'd')
		      { 
			 cout<<"we will now encrypt the string"<<endl;
			 word2 = doDendUsingCrypto(word2,keyNormal, cryptogram);
			 cout<<"----------------------------------------------------------------------------------"<<endl;
			 cout<<"encryption finished"<<endl;
			 cout<<"printing encrypted string"<<endl;
			 printWordsFromVector(word2);
			 outPutFile(word2);
			 cout<<"enter Q or q to quit or enter any key to return to earlier instruction"<<endl;
			 cin >> secChoice;
			 secChoice = tolower(secChoice);
		      }
		   else if (secChoice =='q')
		     {
		       cout<<"returning to earlier menu"<<endl;
		     }
		  } while (secChoice != 'q');
		  }
	  else if (choice == 'q')
	    {
	      break;
	    }
	  else
	    {
	      cout <<"invalid character entered. please enter a valid choice"<<endl;
	      cin >> secChoice;
	      secChoice = tolower(secChoice);
	    }
    }while(choice != 'q');
}
/*
  Enters data into a vector from a variable txt file. 
  variables: ifstream fin, string fname, string word


  returns vector <string> x

*/
vector <string> getDataForEncryption()
{
  vector <string> x;
  ifstream fin; 
  string fname; 
  string word;
  cout<<"enter file name contain string to be encrypted or decrytped"<<endl;
  cin>>fname;
  fin.open(fname.data());
  while (fin>>word)
    {
      x.push_back(word);
    }
  fin.close();
  return x;
}

/*
  returns a vector <string> endRot which contains encrypted strings 
  variables: int rot: rotation number, vector <string> g: vector that is passed into the function, strign decWord string that is returned.
  function: endLetterUsingRot: takes in vector g and int rot

  returns vector <string> endRot

*/
vector<string>doEndUsingRot(vector<string> g, int rot)
{
  vector <string> endRot;
  for(int j = 0; j < g.size(); j++)
    {
      string decWord = endLetterUsingRot(g[j],rot);
 
      endRot.push_back(decWord);
    }
  return endRot;
}
/*
  returns a vector <string> endRot which contains decrypted strings
  variables: ifstream fin, string fname, string word


  returns vector <string> dendRot

*/
vector <string> doDendUsingRot(vector<string> j1, int rot2)
{
  vector <string> dendRot;
  for (int g2 = 0; g2 < j1.size(); g2++)
    {
      string encWord = dendLetterUsingRot(j1[g2], rot2);
      dendRot.push_back(encWord);
    }
  return dendRot;
}

/*
  returns a string that contains encrypted charactrs.
  variables: string word, int Rot: rotation number that is obtained from function vector<string> doEndUsingRot


  returns string endWord 

*/
string endLetterUsingRot(string word, int Rot)
{
  string newWord = toLower(word); //changes word into lowercase.
  string endWord = newWord; 
  for(int k = 0; k < newWord.size(); k++)
    {


      if (newWord[k] >= 'a' && newWord[k] <= 'z')
	{
     
	  int newch = newWord[k] + (Rot%26);
	  if (newch > 'z')
	    {
	      newch-=26;
	 
	    }

          endWord[k] = newch;
	}
    }
    return endWord;
}
/*
  returns a string that contains decrypted characters 
  variables: string word3,int Rot1:rotation number that is obtained from function vector<string> doEndUsingRot.


  returns string dendWord

*/
string dendLetterUsingRot(string word3, int Rot1)
{
  string dendWord = word3;
  for (int g1 = 0; g1 < word3.size(); g1++)
    {
      if(word3[g1] >= 'a' && word3[g1] <='z')
	{
	  int oldch = word3[g1] -(Rot1%26);
	  if(oldch < 'a')
	    {
	      oldch += 26;
	    }
	 dendWord [g1] = oldch;
	}
    }
  return dendWord;
}
/*
  prints out vector that is passed into function.
  variables: vector <string> d: any vector that is passed into the function

  returns nothing. 

*/
void printWordsFromVector(vector<string>d)
{
  for (int h = 0; h < d.size(); h++)
    {
      cout<<d[h]<<"\t";
    }
  cout<<endl;
  return; 
}
/*
  returns string that is encrypted using a Cryptogram.
  variables: vector <string> h3, string normalKey: contains a string going from a to  z, string cryptogramKey contains the cryptogram key used for encryption
  function: endLetterUsiongCrypto is used to encrypt every individual string within the vector
  returns a vector

*/
 vector <string> doEndUsingCrypto(vector <string> h3, string normalKey, string cryptogramKey)
{
  vector <string> endCrypto;
  for (int h4 = 0; h4 < h3.size(); h4++)
    {
      string encWord5  =  endLetterUsingCrypto(h3[h4],normalKey,cryptogramKey);
      endCrypto.push_back(encWord5);
    }
  return endCrypto;
}
/*
  function that encrypts each letter in the string using a cryptogram
  string word4, string key1: string containing a to z, string key2: string containing cryptograms

  returns string endWord6

*/
string endLetterUsingCrypto(string word4,string key1, string key2)
{
  string newWord4 = toLower(word4);//makes string into lowercase.
  string endWord6 = newWord4;
  for (int g4 = 0; g4 < newWord4.size(); g4++)
    {
      if(newWord4[g4] >= 'a' && newWord4[g4] <= 'z')
	{
      char a = newWord4[g4];
      int f91 =  key1.find(a,0);
      endWord6[g4] = key2[f91];
	}
    }
  return endWord6;

}
/*
  function that decrypts the strings contained within vector<string>h6
  vector <string> h6: contains the encrypted strings, string normalKey1: string that contains characters a to z, string cryptogramKey1: string that contains cryptogram key

  returns vector dendCrypto1

*/
 vector<string> doDendUsingCrypto(vector<string> h6,string normalKey1, string cryptogramKey1)
{

  vector <string>dendCrypto1;
  for (int h5 = 0; h5 < h6.size(); h5++)
    {
      string encWord7 = dendLetterUsingCrypto(h6[h5],normalKey1, cryptogramKey1);
     dendCrypto1.push_back(encWord7);
    }
  return dendCrypto1;
}
/*
  function that decrypts the characters of the string then returns it as a string endWord8
  vector word8: string is stored in this, string key01: string that contains key a to z, string key02: contains cryptogramKey

  returns endWord8

*/
string dendLetterUsingCrypto(string word8, string key01, string key02)
{
  string endWord8 = word8;
  for (int g8 = 0; g8 < word8.size(); g8++)
    {
      if(word8[g8] >= 'a' && word8[g8] <= 'z')
        {
	  char a1 = word8[g8];
	  int rX78 =  key02.find(a1,0);
	  endWord8[g8] = key01[rX78];
        }
    }
  return endWord8;

}

/*
  function that gets cryptogram key and normal key from txt files aKey.txt and cKey.txt
  string fname2: name of text file, string cKey: string that will contain the key

  returns cKey

*/
string getDataKey()
{
  ifstream fin;
  string fname2;
  string cKey;
  cout<<"enter file name containing key"<<endl;
  cin>>fname2;
  fin.open(fname2.c_str());
  if (!fin)
    {
      cout<<"sorry"<<endl;
    }
  else
    {
      while(fin)
	{
	  fin>>cKey;
	}
    }
  fin.close();
  return cKey;
}
/*
  function that outputs a vector to a file name of your choice
  vector <string> kaga: vector that is passed into this function. can contain encrypted or decrypted strings. 

  

*/
void outPutFile(vector <string> kaga)
{
  string fname1;
  ofstream fout;
  cout<<"enter file name to output results to"<<endl;
  cin>>fname1;
  fout.open(fname1.c_str());
  for (int pkun = 0; pkun < kaga.size(); pkun++)
    {
      fout << kaga[pkun] << "\t";
    }
  fout.close();
}

/*
  function that makes the characters of a string into lowercase then returns it as a new string
  string word9: word in vector

  returns newWord

*/
string toLower(string word9)
{
  string newWord;
  newWord = word9;
  for (int n1 = 0; n1 < word9.size(); n1++)
    {
      newWord[n1] = tolower(word9[n1]);
    }
  return newWord;
}
			      
 
