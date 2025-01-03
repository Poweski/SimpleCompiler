## Wstęp

Budowa kompilatora jest zazwyczaj podzielona na dwie główne części: frontend i backend. Frontend kompilatora odpowiada za analizę kodu źródłowego i jest odpowiedzialny za zrozumienie jego struktury oraz znaczenia. W jego skład wchodzą fazy takie jak:
- Analiza leksykalna – przekształca strumień znaków kodu źródłowego w leksemy, które są grupowane w tokeny.
- Analiza składniowa – używa tokenów do zbudowania drzewa składniowego, które odwzorowuje gramatyczną strukturę kodu.
- Analiza semantyczna – sprawdza, czy kod źródłowy jest spójny semantycznie i zgodny z regułami języka.

W swoim projekcie implementuję frontend dla prostego języka inspirowanego C. Dwie ostatnie fazy są zintegrowane w ramach modułu parsera. Backend kompilatora, który zajmuje się generowaniem kodu wynikowego oraz 
optymalizacją, nie jest częścią projektu.

## Opis języka
Program w języku źródłowym składa się z bloku zawierającego opjonalne deklaracje (decl) oraz instrukcje (stmt). Token basic reprezentuje typy podstawowe. Produkcje dla wyrażeń obsługują łączność i pierwszeństwo
operatorów. Wykorzystują hierarchię nieterminali odpowiadających poszczególnym poziomom pierwszeństwa, kończącą się nieterminalem factor dla wyrażeń w nawiasach, identyfikatorów, odwołań do tablic oraz stałych.

program -> block

block -> { decls stmts }

decls -> decls decl | ϵ

decl -> type id ;

type -> type [ num ] | basic

stmts -> stmts stmt | ϵ

stmt -> loc = bool ;
      | if ( bool ) stmt
      | if ( bool ) stmt else stmt
      | while ( bool ) stmt
      | do stmt while ( bool ) ;
      | break ;
      | block
      
loc -> loc [ bool ] | id

## Struktura projektu

Przy wejściu do parsera program źródłowy stanowi strumień tokenów. Przy wyjściu z parsera ma postać drzewa składni, którego konstrukcje lub węzły są implementowane jako obiekty. Obiekty te są odpowiedzialne za 
konstruowanie węzłów drzewa składni, sprawdzanie typów i generowanie trójadresowego kodu pośredniego.

Klasa Word zarządza leksemami dla słów kluczowych, identyfikatorów i tokenów złożonych, takich jak &&. Jest też użyteczna w zarządzaniu w kodzie pośrednim formami operatorów, takich jak unarny minus.
Główna metoda w kalsie Lexer, funkcja scan, rozpoznaje liczby, identyfikatory i słowa kluczowe języka. 
Podczas gdy klasa LExer odwzorowuje ciągi znaków na słowa, klasa Env przypisuje słowom tokenów obiekty klasy Id.
Klasa Type jest podklasą klasy Word, ponieważ podstawowe nazwy typów, takie jak int, są po prostu słowami kluczowymi, które analizator leskykalny ma zamienić z leksemów na odpowiednie obiekty.
Węzły drzewa składni są implementowane jako obiekty klasy Node. Na potrzeby zgłaszania błędów pole lexline zapamiętuje numer wiersza kodu źródłowego, w któym wystąpiła konstrukcja reprezentowana
przez ten węzeł. Klasa ta jest używana w procesie generowania kodu trójadresowego. Metoda gen zwraca term, który może pełnić funkcję prawej strony instrukcji trójadresowej. Dla wyrażenia E = E1 + E2
metoda gen zwraca term x1 + x2, gdzie x1 i x2 są odpowiednio adresami wartości zmiennych E1 i E2. Zwracana domyślnie wartość this jest właściwa, jeśłi obiekt sam jest adresem; podklasy Expr zazwyczaj
nadpisują metodę gen. Metoda reduce oblicza lub redukuje wyrażenie do pojedynczego adresu; inaczej mówiąc, zwraca stałą, identyfikator lub nazwę tymczasową t przechowującą wartość E.
Kod skaczący dla wyrażenia logiczengo B jest generowany przez metodę jumping, która przyjmuje jako parametry dwie etykiety t oraz f, nazywane odpowiednio wyjściami dla prawdy i fałszu wyrażenia B. 
Kod zawiera skok do t, jeśli B okazuje się prawdziwe, oraz skok do f, gdy B jest fałszem. Specjalna etykieta 0 oznacza, że sterowanie przechodzi przez B do następnej instrukcji po kodzie dla B.
Każda konstrukcja będąca instrukcją implementowana jest jako podklasa klasy Stmt.
