---
layout: default
title: Rotating calipers
parent: Geometry
---
# Rotating calipers
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---
## Thuật toán

Tên của thuật toán đến từ ý tưởng của chính nó: xoay thước cặp xung quanh đa giác lồi.
Mỗi khi một cạnh của thước trùng với cạnh của đa giác, 2 điểm của đỉnh nằm trên 2 cạnh
sẽ tạo thành một antipodal pair. Sau khi xoay một vòng, ta sẽ thu được tất cả antipodal 
pairs của đa giác (một antipodals pair của đa giác lồi là một cặp đỉnh của đa giác sao 
cho tồn tại hai đường thẳng song song đi qua chúng và không cắt đa giác).

Giả sử các đỉnh của đa giác đã được xếp theo thứ tự ngược chiều kim đồng hồ và được chứa 
trong mảng $p$. Xuất phát từ đỉnh $A = 0$, trước hết ta tìm đỉnh $B$ có thứ tự lớn nhất mà góc 
tạo bởi vector $\overrightarrow{P_A P_{A+1}}$ và vector $\overrightarrow{P_{B-1}P_B}$ theo chiều 
ngược kim đồng hồ không vượt quá $180^{\circ}$, hay tích chéo giữa hai vector mang giá trị dương (\*). 
$\overrightarrow{P_B}$ cùng với $\overrightarrow{P_A}$ chắc chắn tạo thành một antipodal 
pair. Tiếp theo, để tìm kết quả cho $A+1$, ta chỉ việc tăng $B$ đến $B'$ lớn nhất có thể mà vẫn 
giữ được tính chất (\*), khi đó $\overrightarrow{P_{A+1}}$ và $\overrightarrow{P_B}$ cũng là một 
antipodal pair... Độ phức tạp của thuật toán là $O(n)$.

```
int a = 0, b = 0;
for (;a<n;a++){
	while(góc của 2 vector theo chiều ngược kim đồng hồ < 180 độ) 
		b = (b+1)%n;
	// a và b tạo thành một antipodal pair
}
```

## Ứng dụng
### Tìm khoảng cách lớn nhất giữa hai điểm trong một tập điểm đã cho.
Ta có thể thấy được hai điểm tạo khoảng cách lớn nhất trong tập điểm chắc chắn thuộc bao lồi 
của tập điểm đã cho. 

> Chứng minh
>> Giả sử tồn tại hai điểm có khoảng cách lớn nhất mà có ít nhất một điểm không thuộc bao lồi.
Gọi điểm đó là $A$, điểm còn lại sẽ là $B$; tia $\overrightarrow{BA}$ chắc chắn cắt bao lồi tại 
điểm $B’$ của cạnh $CD$. Khi đó $\|AB\| \leq \|AB'\| \leq max(\|AC\|, \|AD\|)$, điều này là vô lý
vì $\|AB\|$ là khoảng cách lớn nhất trong tập điểm.

>> ![Figure 1](/cpl/assets/posts/geometry/rotating-calipers/figure1.png)

Ngoài ra, hai điểm đó còn tạo thành một antipodal pair (có thể chỉ ra được một cặp đường thẳng
đi qua 2 điểm này và không cắt đa giác, đó là 2 đường thằng song song với nhau và vuông góc 
với đoạn thẳng nối hai điểm này). Từ đây, ta chỉ cần tính khoảng cách giữa hai điểm trong 
mọi antipodal pairs.

### Tìm chiều rộng nhỏ nhất của một đa giác lồi

### Tìm hình chữ nhật có chu vi nhỏ nhất bao một đa giác lồi