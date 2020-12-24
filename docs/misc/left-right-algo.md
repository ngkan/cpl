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

Thuật toán left-right thường được dùng để giải quyết bài toán sau:

**Bài toán:** Cho mảng $a$ gồm $n$ số. Với mỗi $1 \leq i \leq n$, tìm hai số
nguyên $l[i]$ bé nhất và $r[i]$ lớn nhất sao cho $a[i] = min(a[l[i]], ...,
a[r[i]])$ với độ phức tạp $O(n)$.

## Thuật toán

Giả sử ta tính được $l[1], l[2], ..., l[i-1]$. Để tính $l[i]$, ta chạy dòng code
sau

```cpp
l[i] = i;
while (l[i] > 1 && a[i] >= a[l[i]-1])
    l[i] = l[l[i]-1];
```

Việc tìm mảng $r$ cũng được thực hiện tương tự.
## Chứng minh

Tưởng tượng ta có $n$ đỉnh từ $1$ đến $n$, gốc tại $1$ và các cạnh là $i - l[i]$.
Để ý là đồ thị là một cái cây. Khi tính $l[i]$, ta có thể thấy là ta nhảy trên
cây. Do ta luôn bắt đầu nhảy từ $l[i]-1$, ta có thể chứng minh số lần nhảy không
quá $n$.

## Code

```cpp
int n, a[N];

for (int i = 1; i <= n; i++) {
    l[i] = i;
    while (l[i] > 1 && a[i] >= a[l[i]-1])
        l[i] = l[l[i]-1];
}
for (int i = n; i >= 1; i--) {
    r[i] = i;
    while (r[i] < n && a[i] >= a[r[i]+1])
        r[i] = r[r[i]+1];
}
```

## Ứng dụng

Thuật toán gần như chỉ giải quyết bài toán đã nêu.
## So sánh với các thuật toán khác

Về tốc độ, dễ thấy thuật toán Left-Right nhanh-gọn-nhẹ hơn so với các thuật toán
/ CTDL phổ biến khác như Segment Tree hay mảng thưa đối với bài toán đã nêu.
