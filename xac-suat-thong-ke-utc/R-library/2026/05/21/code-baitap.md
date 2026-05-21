# Bài 1: Kiểm định về giá trị trung bình

```
# Tai du lieu mtcars
data(mtcars)

# Bai 1: Kiem dinh mot mau cho bien mpg
# mu = 20 la gia tri gia thuyet
ket_qua_A <- t.test(mtcars$mpg, mu = 20, alternative = "two.sided")

# Xem ket qua
print(ket_qua_A)

# Trich xuat p-value đe ra quyet dinh tu dong
if (ket_qua_A$p.value < 0.05) {
  cat("Bac bo H0: mpg trung binh khac 20\n")
} else {
  cat("Chua đu bang chung bac bo H0: mpg trung binh bang 20\n")
}



# Tai du lieu iris
data(iris)

# Bai 1: Kiem dinh mot mau cho bien Sepal.Length
# mu = 5.8 theo yeu cau cua bai
ket_qua_B <- t.test(iris$Sepal.Length, mu = 5.8, alternative = "two.sided")

# Xem ket qua
print(ket_qua_B)

# Ket luan dua tren p-value [1]
# Neu p-value < 0.05 thi bac bo H0



# Tai du lieu va xu ly NA trong airquality
data(airquality)
aq <- na.omit(airquality) 

# Bai 1: Kiem dinh mot mau cho bien Temp
# mu = 77 theo yeu cau cua bai
ket_qua_C <- t.test(aq$Temp, mu = 77, alternative = "two.sided")

# Xem ket qua
print(ket_qua_C)
```
