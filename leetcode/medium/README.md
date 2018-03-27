# Medium 題解

## 1 ~ 100
* 17 Letter Combination: 水題
* **48** rotate 90 degree: 可以先想想一個簡單的圖形，看看有什麼 STL 可實現的方法，可達成順轉 90 的效果
* 64 min. 2d path sum: 水題
* 78 subset: 水題

## 100 ~ 200

## 200 ~ 300
* 200 Number of Islands: DFS，水題
* 213 Rob on Cycle List: DP 做兩次，code 寫乾淨！要討論的 case 太多可能是想錯了
* **229** Majority Element 的推廣: 好題！ maintain 兩個，最後再來檢查
* 238 Product of Arr except self: 想想如何從 O(n) 空間降到 O(1)
* **287 Find Duplicated Number**: 超級精闢，見[筆記](https://sunprinces.github.io/learning/2018/03/leetcode-287---find-the-duplicate-number/)

## 300 ~ 400
* 347 Top K Freq. Element: Naive 法為 O(N lg N)，但因為不在意回傳的順序，maintain pq
  去記目前 top k 的 elements ，每次 insert 複雜度為 O(lg k) => total 為 O(N lg k)

## 400 ~ 500
* **406 Queue Reconstruction**: 觀察高 or 矮者那一方不受後方插入的影響，先處理那些人
* **494 Target Sum**: 眉眉角角很多 (1. offset 和 bound ，bound不能當offset用，否則在 iterate 時，你 bound+bound+某元素就超過了 2\*bound+1了 ,2. index 從哪裡開始要統一)

## 500 ~ 600

## 600 ~ 700
* ***647*** Palindromic Substrings: 思考 O(N) 的 Manacher's Algorithm

## 700 ~
