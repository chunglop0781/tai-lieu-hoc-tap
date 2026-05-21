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

# Bài 2: Kiểm định về giá trị tỉ lệ
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
# Chuan bi du lieu
k_san <- sum(mtcars$am == 1)   # So luong xe san
n_tong <- nrow(mtcars)         # Tong so xe
# Thực hiện kiểm định
ket_qua_A4 <- prop.test(x = k_san, n = n_tong, p = 0.40, alternative = "two.sided")
print(ket_qua_A4)
# Dem so luong vs=1 va tong so xe cua moi nhom (am=0 va am=1)
k_vs <- table(mtcars$am, mtcars$vs)[, "1"] 
n_nhom <- table(mtcars$am)
# Kiem dinh 2 ti le
ket_qua_A5 <- prop.test(x = k_vs, n = n_nhom, alternative = "two.sided")
print(ket_qua_A5)




# Tai du lieu iris
data(iris)
# Bai 1: Kiem dinh mot mau cho bien Sepal.Length
# mu = 5.8 theo yeu cau cua bai
ket_qua_B <- t.test(iris$Sepal.Length, mu = 5.8, alternative = "two.sided")
# Xem ket qua
print(ket_qua_B)
# Ket luan dua tren p-value [1]
# Neu p-value < 0.05 thi bac bo H0
k_setosa <- sum(iris$Species == "setosa")
n_iris <- nrow(iris)
ket_qua_B4 <- prop.test(x = k_setosa, n = n_iris, p = 1/3)
print(ket_qua_B4)
# Chia du lieu va dem
nua_dau <- iris[1:75, ]
nua_sau <- iris[76:150, ]
k_2nhom <- c(sum(nua_dau$Species == "setosa"), sum(nua_sau$Species == "setosa"))
n_2nhom <- c(nrow(nua_dau), nrow(nua_sau))
ket_qua_B5 <- prop.test(x = k_2nhom, n = n_2nhom)
print(ket_qua_B5)




# Tai du lieu va xu ly NA trong airquality
data(airquality)
aq <- na.omit(airquality) 
# Bai 1: Kiem dinh mot mau cho bien Temp
# mu = 77 theo yeu cau cua bai
ket_qua_C <- t.test(aq$Temp, mu = 77, alternative = "two.sided")
# Xem ket qua
print(ket_qua_C)
# Loai bo NA va tao bien nhi phan
aq <- na.omit(airquality)
aq$ozone_cao <- as.integer(aq$Ozone > 60)
k_o3 <- sum(aq$ozone_cao == 1)
n_aq <- nrow(aq)
ket_qua_C4 <- prop.test(x = k_o3, n = n_aq, p = 0.25)
print(ket_qua_C4)
```

# Bài 3: Diễn giải kết quả
```
```
