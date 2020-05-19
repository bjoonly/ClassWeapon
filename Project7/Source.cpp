#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;
class Weapon {
	int range;
	float caliber;
	int bulletsInStore;
	int maxBulletsInStore;
public:
	void Initialize(int range, float caliber, int maxBulletsInStore) {
		setRange(range);
		setCaliber(caliber);
		setMaxBulletsInStore(maxBulletsInStore);
		setBulletsInStore(0);
	}
	void setRange(int range) {
		if (range < 1) {
			cout << "Inavalid value for range.\n";
			range = 1;
		}
		this->range = range;
	}
	void setCaliber(float caliber) {
		if (caliber < 1) {
			cout << "Inavalid value for caliber.\n";
			caliber = 1;
		}
		this->caliber = caliber;
	}
	void setMaxBulletsInStore(int maxBulletsInStore) {
		if (maxBulletsInStore < 1) {
			cout << "Inavalid value for max bullets in store.\n";
			maxBulletsInStore = 1;
		}
		this->maxBulletsInStore = maxBulletsInStore;
	}
	void setBulletsInStore(int bulletsInStore) {
		if (bulletsInStore < 0) {
			cout << "Inavalid value for bullets in store.\n";
			bulletsInStore = 0;
		}
		else if (bulletsInStore > maxBulletsInStore) {
			cout << "Inavalid value for bullets in store.\n";
			bulletsInStore = maxBulletsInStore;
		}
		this->bulletsInStore = bulletsInStore;
	}
	bool Shot() {
		if (bulletsInStore > 0) {
			--bulletsInStore;
			return 1;
		}
		else 
			return 0;	
	}
	void Recharge() {
		setBulletsInStore(maxBulletsInStore);
	}
	void ShowWeapon()const {
		cout << "Range: " << range << endl << "Caliber: " << caliber << endl << "Bullets in store: " << bulletsInStore << endl <<
			"Max bullets in store: " << maxBulletsInStore << endl;
	}
	void Save()const{
		ofstream fout;
		fout.open("Weapon.txt");
		bool isOpen = fout.is_open();
		if (isOpen == false) {
			system("cls");
				cout << "The file couldn't be opened.\n";
				Sleep(2500);
				return;
		}
		fout << range << endl << caliber << endl << bulletsInStore << endl << maxBulletsInStore << endl;
		fout.close();
	}
	void Load() {
		ifstream fin;
		fin.open("Weapon.txt");
		bool isOpen = fin.is_open();
		if (isOpen == false) {
			system("cls");
			cout << "The file couldn't be opened.\n";
			Sleep(2500);
			return;
		}
		fin>>range;
		fin>>caliber;
		fin>>bulletsInStore;
		fin>>maxBulletsInStore;
		fin.close();
	}
	
}w1,w2,w3;

int main() {
	w1.Initialize(150,7.62f,7);
	w2.Initialize(600,7.62f,5);
	cout << "\tWeapon 1:\n";
	w1.ShowWeapon();
	cout << "\nRecharge weapon 1:\n";
	w1.Recharge();
	w1.ShowWeapon();
	cout<<"\nResult of shot: "<<w1.Shot()<<endl;
	w1.ShowWeapon();
	cout << "\nSave weapon 1.\n";
	w1.Save();
	cout << "\nResult of shot: " << w1.Shot() << endl;
	w1.ShowWeapon();
	cout << "\n\tWeapon 2:\n";
	w2.ShowWeapon();
	cout << "\nResult of shot: " << w2.Shot() << endl;
	w2.ShowWeapon();
	w3.Load();
	cout << "\n\tWeapon 3:\n";
	w3.ShowWeapon();
	return 0;
}