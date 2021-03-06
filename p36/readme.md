## 朴素想法
遍历所有数字，检查每个数是否同时是十进制回文和二进制回文。对所有满足条件的数字求和。

## 可优化点

1. 根据二进制回文的特点，可知满足条件的数字必须是奇数，所以待检查的数字范围可以减半。
2. 小范围采样可知，有限范围内，十进制回文数比二进制回文数少，所以可以先判定十进制回文数。
3. 二进制回文的判定，可以采用位移计算生成二进制逆序的数值，然后通过判断俩数是否相等来看是否回文。


