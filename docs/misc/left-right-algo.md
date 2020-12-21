---
layout: default
title: Thuật toán Left-Right
parent: Misc
---

# Thuật toán Left-Right
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

## Giới thiệu

Thuật toán left-right thường được dùng để giải quyết bài toán

 Cho mảng a gồm n số. Với mỗi i, tìm l[i], r[i] sao cho a[i] = min(a[l[i]], ..., a[r[i]])

với độ phức tạp $O(n)$

## Thuật toán

Giả sử mình tính được l[1], l[2], ... đến l[i-1]. Để tính l[i], mình sẽ dùng lặp lệnh này đến khi không lặp được nữa

	if a[i] >= a[l[i]-1]
  	    l[i] = l[l[i]-1]

## Chứng minh

## Ứng dụng

## So sánh với các thuật toán khác

Nhanh
