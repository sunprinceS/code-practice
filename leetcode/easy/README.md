# Easy 題解

## 1 ~ 100
* 21 merge sorted linked list: 水題
* 70 climb stairs: Fibonacci, DP

## 100 ~ 200
* 101 Symmetric Binary Tree: 水題
* 104 找樹的深度: D&C
* 155 stack 變形: 建兩個stack, 一個正常, 一個記 min element
* 167 sorted 2sum: 水題
* 169 Majority Element: 善加利用 M.E **必定**存在這個條件
* 198 Rob House in List: DP

## 200 ~ 300
* 206 reverse LinkedList: 水題
* 258 addDigit: 小聰明題，觀察
* 283 moveZeroes: 注意全非 0 的 case

## 300 ~ 400
* 338 countBits: 觀察，注意到 ret[i&(i-1)] + 1 是個更簡潔的寫法(進位時(i.e i = pow(2,\*))，i&(i-1) 為 0)
* 412 fizzBuzz: 水題
* **448** findDisappearedNumbers: 利用將對應位置 mark 成負，保有 array 資訊的情況同時立 flag
* 461 Hamming Distance: 利用 `__buildin_popcount` 一行結束！
* 463: 

## 400 ~ 500

## 500 ~ 600
* 538 BST 相關: modified inorder traversal，maintain 一個 類似 global ref 有助於處理
* 543 Binary Tree Diameter: maintain 一個 global max 去記當前最大值，然後 traverse 拿到 depth

## 600 ~ 700
* 617 Merge B Tree: 水題

## 700 ~
* 746 ClimbStair 變形: DP
* 747 dominant number: ~吃了 3 次 WA，條件考慮要小心~，直接用最直覺的方法做即可... = =

