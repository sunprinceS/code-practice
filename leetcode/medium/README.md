# Medium 題解

## 1 ~ 100
* **11 Container w/ motst water**: 弄清楚優化的方向，再設計演算法
* 17 Letter Combination: 水題
* 39 Combination Sum: DFS，target = 0這個條件好用， time complexity: O(N^h), N is # of candidates, h is target/min(candidates)
* 40 Combination Sum2: DFS, 39 的變形
* **48** rotate 90 degree: 可以先想想一個簡單的圖形，看看有什麼 STL 可實現的方法，可達成順轉 90 的效果
* **49**: 水題，考 hash 的觀念
* 55: 原想法是D&C，但可用 greedy 去解且較簡潔
* 62: 組合數，用 DP (C++沒有內建的bin. coeff function)
* 64 min. 2d path sum: 水題
* 74 Searcg 2D Matrix: 小心 corner case
* 75 Sort: 意義不明= = ，水題
* 78 subset: 水題
* 79 find word: 水題
* 96 Unique BST: DP水題，求的其實就是卡特蘭數

## 100 ~ 200

## 200 ~ 300
* 200 Number of Islands: DFS，水題
* 207 Course Schedule: DFS 找 cycle，直接 recursive 寫，用 stack 硬幹太髒，加
* 210 Course Schedule: DFS 找 topological order，最後要 reverse
  superNode 時，status 和 edges 都要多開一個
* 213 Rob on Cycle List: DP 做兩次，code 寫乾淨！要討論的 case 太多可能是想錯了
* 215 Kth Largest Element: 跟 347 方法一樣
* **229** Majority Element 的推廣: 好題！ maintain 兩個，最後再來檢查
* 238 Product of Arr except self: 想想如何從 O(n) 空間降到 O(1)
* **240 Search 2D Matrix**: 看一下 [此作法](https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66207/My-C++-soluation-using-Binary-search-Tree-model-beats-100~~~~)
* 279 Perfect Square: D&C with memorization, O(sqrt(n)), 每一步有 Greedy 策略
* **287 Find Duplicated Number**: 超級精闢，見[筆記](https://sunprinces.github.io/learning/2018/03/leetcode-287---find-the-duplicate-number/)

## 300 ~ 400
* 309 Buy & Sell: 注意要開 tmp variable ( DP 如果只開一個變數去記，要小心覆寫的問題)
* 322 Coin Change: 279 的 general 版本， O(amount * n)，不存在 greedy 策略 (因不保
  證一定可換)
* 347 Top K Freq. Element: Naive 法為 O(N lg N)，但因為不在意回傳的順序，maintain pq
  去記目前 top k 的 elements ，每次 insert 複雜度為 O(lg k) => total 為 O(N lg k)
* 394 Decode: 用 stack 解很漂亮！

## 400 ~ 500
* **406 Queue Reconstruction**: 觀察高 or 矮者那一方不受後方插入的影響，先處理那些人
* **494 Target Sum**: 眉眉角角很多 (1. offset 和 bound ，bound不能當offset用，否則在 iterate 時，你 bound+bound+某元素就超過了 2\*bound+1了 ,2. index 從哪裡開始要統一)

## 500 ~ 600

## 600 ~ 700
* ***647*** Palindromic Substrings: 思考 O(N) 的 Manacher's Algorithm

## 700 ~
* **714 Sell & Buy w/ fee**: 很好的 DP 題目
* 763 Partition Labels: 水題
