
#include <iostream>
#include <string>
#include <fstream>

void init(int* arr, int n) {

    for (int i = 0; i < n; i++) {

        arr[i] = pow(2,i);
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void init(int** arr, int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            arr[i][j] = rand() % 10;
            std::cout << arr[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void createFile(std::string file) {

    std::ofstream fout(file);

    for (int i = 0; i < 25; i++) {

        for (int j = 0; j < 25; j++) {

            fout << rand()%10 << " ";
        }

        fout << std::endl;
    }

    fout.close();
}

void combineFiles(std::string file1, std::string file2) {

    std::ifstream fin(file1);
    std::ofstream foutput("new.txt");
    std::string str;

    if (fin.is_open()) {

        while (!fin.eof()){

          std::getline(fin, str);
          foutput << str << std::endl;
        }
    }

    fin.close();

    std::ifstream fin2(file2);
    if (fin2.is_open()) {

        while (!fin2.eof()) {

            std::getline(fin2, str);
            foutput << str << std::endl;
        }
    }
    fin2.close();
    foutput.close();
    std::cout << file1 << " and " << file2 << " are combined into newF.txt" << std::endl;
}

std::string isWordFound(std::string word, std::string file) {

    std::ifstream fin(file);
    std::string str, result = "The word is NOT found";

    if (fin.is_open()) {

        while (!fin.eof()) {

            std::getline(fin, str);
            if (str.find(word) != std::string::npos)
            {
                result = "The word is found!";
                break;
            }
        }
    }

    fin.close();

    return result;
 }

int main()
{
    // TASK 1
    std::cout << "Enter a number " << std::endl;
    int n;
    std::cin >> n;

    int* arr = new (std::nothrow) int[n];

    if (arr != nullptr) {

        std::cout << "Task1: ";
        init(arr, n);

        delete[] arr;
    }
    else {
        std::cout << "Error! Cannot allocate memory" << std::endl;
    }
    
    // TASK 2
    const size_t SIZE4 = 4;
    int** matrix = new int* [SIZE4];
    for (int i = 0; i < SIZE4; i++) {

        matrix[i] = new int[SIZE4];
    }

    std::cout << "Task2: " << std::endl;
    init(matrix, SIZE4);
   
    for (int i = 0; i < SIZE4; i++) {

        delete[] matrix[i];
    }
    delete[] matrix;   

    // TASK 3
    std::cout << "Task3: Please enter two names of files  " << std::endl;
    std::string file1, file2;
    std::cin >> file1 >> file2;

    createFile(file1 + ".txt");
    createFile(file2 + ".txt");  

    // TASK 4
    std::cout << "Task4: ";
    combineFiles(file1 + ".txt", file2 + ".txt");    

    // TASK 5
    std::cout << "Task5: Please enter a word and a file name" << std::endl;
    std::string word, file;
    std::cin >> word >> file;

    std::cout << isWordFound(word, file) << std::endl;
}
