# import <stdio.h>
# import <stdlib.h>
# import <math.h>


int first_digit(long n);
int second_digit(long n, double length);
int card_validation(long n, int size);
int main(void)
{
    long card_num;
    int num_length;
    
    do
    {
        printf("Number: ");
        scanf("%ld", &card_num);
        num_length = floor(log10(labs(card_num))) + 1;
    } while(num_length != 13 && num_length != 15 && num_length != 16);
    
    // Get first and second digit
    int first = first_digit(card_num);
    int second = second_digit(card_num, num_length);
        
    if((num_length == 13 && first == 4) || (num_length == 16 && first == 4))
    {
        // testing checksum validation
        int valid = card_validation(card_num, num_length);
        if(valid)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        };
    }
    else if(num_length == 16 && first == 5 && second >= 1 && second <= 5)
    {
        int valid = card_validation(card_num, num_length);
        if(valid)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        };
    }
    else if(num_length == 15 && first == 3 && (second == 4 || second == 7))
    {
        int valid = card_validation(card_num, num_length);
                if(valid)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        };
    }
    else
    {
        printf("INVALID\n");
    };
};

int first_digit(long n)
{
    while(n >= 10)
    {
        n /= 10;
    };
    return n;
};

int second_digit(long n, double length)
{
    long base = pow(10, length-2);
    return (n/base) % 10;
};

// credit card checksum validation algorithm
int card_validation(long n, int size)
{
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int total_sum = 0;
    int arr[size/2], arr2[abs(size - (size/2))], last;
    
    while(n !=0)
    {        
        last = n%10;
        n /= 10;
        counter++;
        
        if(counter%2 == 0)
        {   
            int sum = last*2;
            arr[counter2] = sum;
            counter2++;
        }
        else
        {
            arr2[counter3] = last;
            counter3++;
        };
    };
    
    // split and evaluate
    for(int i=0; i < size/2; i++)
    {   
        if(arr[i] >= 10)
        {
           total_sum += first_digit(arr[i]);
           total_sum += arr[i]%10;
        }
        else
        {
            total_sum += arr[i];
        };
    };
    
    for(int i=0; i < abs(size - (size/2)); i++)
    {
        total_sum += arr2[i];
    };
    
    if(total_sum%10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    };
};
