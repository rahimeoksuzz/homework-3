#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

//aşağıdaki satırları yoruma alarak kodunuzu farklı şekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{
	if (numberOfStones == 1) { //1 taş varsa sadece 1 farklı yol vardır
		return 1; 
	}
	else if (numberOfStones == 2) { //2 taş varsa 1+1 ve 2 olarak 2 yol vardır.
		return 2;
	}
	else if (numberOfStones == 3) { //3 taş varsa 1+1+1, 1+2, 2+1 ve 3 olarak 4 yol vardır.
		return 4;
	}
	else {
		return 	recursiveFunction(numberOfStones - 1) + recursiveFunction(numberOfStones - 2) + recursiveFunction(numberOfStones - 3);
	}
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{
	vector<long long> vect_array(numberOfStones);
	vect_array[0] = 1;
	vect_array[1] = 2;
	vect_array[2] = 4;
	for (int i = 3; i < numberOfStones; i++)
	{
		vect_array[i] = vect_array[i - 1] + vect_array[i - 2] + vect_array[i - 3];
	}
	return vect_array[numberOfStones - 1];
}




int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}
