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
# Thuc hien kiem dinh
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
# Thuc hien kiem dinh
ket_qua_A4 <- prop.test(x = k_san, n = n_tong, p = 0.40, alternative = "two.sided")
print(ket_qua_A4)
# Dem so luong vs=1 va tong so xe cua moi nhom (am=0 va am=1)
k_vs <- table(mtcars$am, mtcars$vs)[, "1"] 
n_nhom <- table(mtcars$am)
# Kiem dinh 2 ti le
ket_qua_A5 <- prop.test(x = k_vs, n = n_nhom, alternative = "two.sided")
print(ket_qua_A5)
# Tach du lieu mpg theo nhom am (0: tu dong, 1: san) [3]
mpg_auto <- mtcars$mpg[mtcars$am == 0]
mpg_manual <- mtcars$mpg[mtcars$am == 1]
# --- KIEM TRA PHUONG SAI (var.test) ---
# Muc dich: De xac dinh tham so var.equal trong ham t.test [2, 3]
f_test <- var.test(mpg_auto, mpg_manual)
is_var_equal <- f_test$p.value >= 0.05 
# --- KIEM DINH TRUNG BINH 2 MAU (Dinh nghia ket_qua_A3) ---
# Kiem dinh H0: mpg trung binh xe tu dong = xe san [1, 2]
ket_qua_A3 <- t.test(mpg_auto, mpg_manual, var.equal = is_var_equal, alternative = "two.sided")
# Gia su ket qua t-test da luu vao bien: ket_qua_A3
alpha <- 0.05
cat("--- DIEN GIAI KET QUA CAU 3 (NHOM A) ---\n")
cat("B1: H0: mpg trung binh xe tu dong = xe san; H1: mpg trung binh khac nhau\n")
cat("B2: Muc y nghia alpha =", alpha, "\n")
ket_qua_A3 <- t.test(mpg_auto, mpg_manual, var.equal = is_var_equal, alternative = "two.sided")
cat("B3: p-value =", round(ket_qua_A3$p.value, 4), "\n")
# B4 & B5: Ra quyet dinh va ket luan bang loi
if (ket_qua_A3$p.value < alpha) {
  cat("B4: Vi p-value < alpha, ta bac bo H0.\n")
  cat("B5: Ket luan: Co bang chung thong ke cho thay muc tieu thu nhien lieu (mpg) giua xe tu dong va xe san la khac nhau.\n")
} else {
  cat("B4: Vi p-value >= alpha, ta chua du bang chung bac bo H0.\n")
  cat("B5: Ket luan: Chua thay su khac biet co y nghia ve mpg giua xe tu dong va xe san.\n")
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
# Gia su ket qua prop.test da luu vao bien: ket_qua_B4
alpha <- 0.05
cat("--- DIEN GIAI KET QUA CAU 4 (NHOM B) ---\n")
cat("B1: H0: Ti le hoa setosa = 1/3; H1: Ti le hoa setosa khac 1/3\n")
cat("B3: p-value =", round(ket_qua_B4$p.value, 4), "\n")
if (ket_qua_B4$p.value < alpha) {
  cat("B4: Bac bo H0.\n")
  cat("B5: Ti le hoa setosa trong du lieu thuc te khac biet co y nghia so voi muc 1/3.\n")
} else {
  cat("B4: Chua du bang chung bac bo H0.\n")
  cat("B5: Ti le hoa setosa xap xi bang 1/3, khong co su khac biet dang ke.\n")
}




# Tai du lieu va xu ly NA trong airquality
data(airquality)
aq <- na.omit(airquality) 
aq$ozone_cao <- as.integer(aq$Ozone > 60)
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
# --- KIEM DINH TI LE 1 MAU ---
k_o3 <- sum(aq$ozone_cao == 1)
n_aq <- nrow(aq)
ket_qua_C4 <- prop.test(x = k_o3, n = n_aq, p = 0.25)
# --- KIEM DINH TI LE 2 MAU ---
# Tach du lieu thang 7 va thang 8 theo yeu cau [1]
thang7 <- subset(aq, Month == 7)
thang8 <- subset(aq, Month == 8)
# Dem so ngay Ozone cao va tong so ngay cua moi thang
k_thang <- c(sum(thang7$ozone_cao == 1), sum(thang8$ozone_cao == 1))
n_thang <- c(nrow(thang7), nrow(thang8))
# Thuc hien kiem dinh va luu vao bien ket_qua_C5 [2]
ket_qua_C5 <- prop.test(x = k_thang, n = n_thang, alternative = "two.sided")
# Gia su ket qua prop.test da luu vao bien: ket_qua_C5
alpha <- 0.05
cat("--- DIEN GIAI KET QUA CAU 5 (NHOM C) ---\n")
cat("B1: H0: Ti le Ozone cao o thang 7 va thang 8 bang nhau.\n")
cat("B3: p-value =", round(ket_qua_C5$p.value, 4), "\n")
if (ket_qua_C5$p.value < alpha) {
  cat("B4: Bac bo H0.\n")
  cat("B5: Co su khac biet co y nghia ve ti le ngay co Ozone cao giua thang 7 va thang 8.\n")
} else {
  cat("B4: Chua bac bo duoc H0.\n")
  cat("B5: Ti le ngay co Ozone cao giua thang 7 va thang 8 la tuong duong nhau.\n")
}
```
