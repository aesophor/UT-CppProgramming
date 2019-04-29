# Midterm
U10516045 資科三 王冠中

## 問答題
1. 請簡述namespace命名空間的功能。
   > Namespace是C++中，預防開發大型專案時發生name conflicts的機制。
   > 不同namespace下可以存在相同名稱的variables、functions、class/struct等等，並利用 :: 運算子來解析範疇(指明所屬的namespace)。
   >
   > 例如：std::vector 即是 std namespace 下的 vector class，使用者可以自訂一個namespace然後也寫一個自己的vector class
   
2. 請簡述vector、deque、list容器的功能。
   > vector：傳統的array大小是固定的，而vector底層也是使用array儲存資料，但它會視資料的量動態縮放大小，所以大小是彈性的。此外因爲vector內部資料在記憶體中是連續的，可直接使用 operator[] 在O(1)時間存取資料。
   >
   > deque：vector只提供push_back()和pop_back()，而deque除了允許從back存取之外還允許從front存取。但deque的資料在記憶體中未必是連續的。
   >
   > list：實際上是使用doubly linked list實作，element在記憶體中非連續，不允許O(1)時間random access，搜索時間是O(n)的線性搜索。
   
3. 試簡述舊式標頭與新式標頭的差異。
   > 舊式headers: 有.h後綴名 (e.g., #include \<iostream.h\>)
   >
   > 新式headers: 沒有.h後綴名 (e.g., #include \<iostream\>)
   >
   > 使用舊式header時，compiler通常會回報warning給使用者，表示此header已被deprecated，應使用新式headers。
   
4. 試簡述ios類別的主要功用。
   > 
   
5. 如果沒有撰寫處理例外的程式碼，C++的預設處理機制會怎麼做呢？
   > 在C++中，若有uncaught exception發生，exception handling subsystem會呼叫std::unexpected()函式，此函式預設會呼叫std::terminate()，而std::terminate()又會呼叫std::abort()終止process。
   > 
   > user可以用 std::set_unexpected(&func) 來設定自己的 uncaught exception handler以重新拋出一個例外，但如果新拋出的例外在外層仍沒有對應的catch block，terminate()仍會自動被呼叫，程序就會照樣終止。
   
6. 關於constructor說明，下列何者正確？
   1. constructor與class同名
   2. constructor可以overload
   3. constructor必須有return value
   4. 當物件產生時，資料成員是由constructor初始化
   > Ans: (1)、(2)、(4)
   
7. 下列說明何者正確？
   1. class中必須撰寫constructor
   2. 若要建立一個共用的變數，可將改變數定義成static資料成員
   3. class定義的右大刮號之後不用加上;
   4. 成員函式宣告爲private，表示該成員是公開形態
   > Ans: (2)
   > 
   > 1. 可以不用寫，若沒寫任何constructor，compiler會幫該class自動宣告一個default constructor
   > 3. 要
   > 4. private是私有成員
   
8. 下列何者敘述正確？
   1. C語言可以使用指標變數、參考型別變數、陣列
   2. C語言設定const變數時一定要設定初值
   3. C++設定const變數時一定要設定初值
   4. C語言可以使用string類別
   > Ans: (3)
   > 
   > 1. C 沒有reference
   > 2. C 可以不用
   > 3. C++ const變數沒給初值，compiler會提示"uninitialized const x"
   > 4. C 沒有class，所有沒有string類別。C 只能用 strcpy, strcmp 等函數對 char array 進行操作。
