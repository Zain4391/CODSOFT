#include<iostream>
#include<random>
using namespace std;

int main()
{
    srand(time(NULL));
    int rand_num = rand() % 10; 
    int guess;
    
    cout<<"Enter a guess value (+ve): "<<endl;
    cin>>guess;
    while (guess != rand_num)
    {
         if (guess > rand_num)
        {
            cout<<"Your guess is too high. Try Again."<<endl;
        }
        else if(guess < rand_num)
        {
            cout<<"Your guess is too low. Try Again."<<endl;
        }
        cin>>guess;
    }

    cout<<"Congratulations! You guessed correctly!"<<endl;

    return 0;
    
}