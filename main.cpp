#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

string judulGame() {
    return "POKEMON BATTLE ";
}

int hitungDamage(int serangan, int pertahanan) {
    return serangan - pertahanan;
}

void tampilkanStatus(string nama, int hp) {
    cout << nama << " HP: " << hp << endl;
}

class Pokemon {
public:
    void tampilkanPokemon() {
        cout << "\nPilih Pokemon:" << endl;
        cout << "1. Pikachu" << endl;
        cout << "2. Charmander" << endl;
        cout << "3. Squirtle" << endl;
    }

    void pilihPokemon(int pilihan, string &nama, int &hp, int &serangan) {
        if (pilihan == 1) {
            nama = "Pikachu";
            hp = 100;
            serangan = 25;
        }
        else if (pilihan == 2) {
            nama = "Charmander";
            hp = 110;
            serangan = 20;
        }
        else if (pilihan == 3) {
            nama = "Squirtle";
            hp = 120;
            serangan = 18;
        }
    }
};

int main() {
    cout << "Kelompok: 52" << endl;
    cout << judulGame() << endl;

    Pokemon pokemon;

    pokemon.tampilkanPokemon();

    int pilihan;
    cout << "Pilih Pokemon: ";
    cin >> pilihan;

    string nama;
    int hp = 0;
    int serangan = 0;

    pokemon.pilihPokemon(pilihan, nama, hp, serangan);

    if (hp == 0) {
        cout << "Pilihan Pokemon tidak tersedia." << endl;
        return 0;
    }

    string musuh = "Francisciscis";
    int hpMusuh = 100;
    int pertahananMusuh = 10;

    cout << "\nKamu memilih " << nama << "!" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout <<"Selamat datang di kota ini! Silahkan lakukan trial pertarungan!" <<endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Musuh: " << musuh << endl;

    while (hp > 0 && hpMusuh > 0) {
        cout<<" ";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "\n=== STATUS ===" << endl;
        tampilkanStatus(nama, hp);
        tampilkanStatus(musuh, hpMusuh);

        cout << "\n1. Serang" << endl;
        cout << "2. Kabur" << endl;

        cout << "Pilih aksi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int damage = hitungDamage(serangan, pertahananMusuh);

            hpMusuh -= damage;

            cout << nama << " menyerang " << musuh << "!" << endl;
            cout << "Damage: " << damage << endl;

            if (hpMusuh > 0) {
                hp -= 15;
                cout << musuh << " menyerang balik!" << endl;
                cout << "HP kamu berkurang 15." << endl;
            }
        }
        else if (pilihan == 2) {
            cout << "Kamu memilih kabur." << endl;
            break;
        }
        else {
            cout << "Pilihan tidak tersedia." << endl;
        }
    }

    if (hpMusuh <= 0) {
        cout << "\nKAMU MENANG!" << endl;
    }
    else if (hp <= 0) {
        cout << "\nKAMU KALAH!" << endl;
    }
    else {
        cout << "\nPertarungan selesai." << endl;
    }

    return 0;
}
