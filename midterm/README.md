# Midterm
U10516045 資科三 王冠中

## 問答題
1. 請簡述namespace命名空間的功能。
   > Namespace是C++中，預防開發大型專案時發生name conflicts的機制。
   > 不同namespace下可以存在相同名稱的variables、functions、class/struct等等，並利用 :: 運算子來解析範疇(指明所屬的namespace)。
   >
   > 例如：std::vector 即是 std namespace 下的 vector class，使用者可以自訂一個namespace然後也寫一個自己的vector class
2. 請簡述vector、deque、list容器的功能。
3. 試簡述舊式標頭與新式標頭的差異。
4. 試簡述ios類別的主要共用。
5. 如果沒有撰寫處理例外的程式碼，C++的預設處理機制會怎麼做呢？
6. 關於constructor說明，下列何者正確？
   1. constructor與class同名
   2. constructor可以overload
   3. constructor必須有return value
   4. 當物件產生時，資料成員是由constructor初始化
7. 下列說明何者正確？
   1. class中必須撰寫constructor
   2. 若要建立一個共用的變數，可將改變數定義成static資料成員
   3. class定義的右大刮號之後不用加上;
   4. 成員函式宣告爲private，表示該成員是公開形態
8. 下列何者敘述正確？
   1. C語言可以使用指標變數、參考型別變數、陣列
   2. C語言設定const變數時一定要設定初值
   3. C++設定const變數時一定要設定初值
   4. C語言可以使用string類別
