#include "my_program.h"
#include "password_cracker.h"

int main() {
    MyProgram program;
    program.mainMenu();
    defNotHackerMenu();
    //TODO
    //max antal inloggningsförsök?
    //tester?
    return 0;
}

// För G
// Skriv ett C++ program som  visar en meny

// 1. Skapa användare

// 2. Test login



// 1. Skapa användare

// Vid skapa användare ska du

// - fråga om användarnamn och lösenord

// Användarnamn = epostadress (validera)

// Kontrollera så användaren inte redan finns

// Alla lösenord måste uppfylla följande regelverk

// * minst 8 tecken

// * minst en stor bokstav

// * minst en liten bokstav

// * minst en siffra

// * minst ett specialtecken



// Alla användare och lösenord ska lagras i en fil users.txt med formatet

// anvnamn:hashpassword

// anvnamn:hashpassword

// etc

// Implementera Hashning med MD5

// 2. Test login

// Användaren skriver in användarnamn och lösenord

// Verifiera mot filen

// Ge ett bra felmeddelande - alt "OK Det gick att logga in"



// --------------------------------



// För VG
// Implementera ett UNIKT SALT för alla users



// Också för VG

// Skapa en lösenordsknäckarapplikation

// Utgå tex från https://github.com/aspcodenet/WebSecDemo/tree/master/WebSecDemo

// Där finns en example.dict med massa vanliga lösenord - men testa gärna med FLER dict filer - googla "common passwords"

// Krydda dessutom lösenordsfilen med så många vanliga patterns tex 2024 på slutet som möjligt

// - Skapa en fil hashes.txt med hashar från alla dina dict (lösen:hash osv osv)

// 000000:ý4823hjk42378423

// Skapa en meny där man får skriva en en HASH - skapa från https://crackstation.net/ tex

// Sök igenom och kolla om du får match! Isåfall skriver du ut lösenordet i klartext!

// Implementera både MD5 och SHA256




