# Bài 1: Mô tả thống kê về các mối quan hệ
```
# Nap du lieu cars
data(cars)
# Ve do thi Scatter plot giua dist va speed
plot(dist ~ speed, data = cars, main = 'Moi quan he giua Toc do va Quang duong phanh', xlab = 'Toc do (mph)', ylab = 'Quang duong phanh (ft)', pch = 19, col = 'blue')




# Nap du lieu trees 
data(trees)
# Ve ma tran Scatter plot cho toan bo cac bien
pairs(trees, main = 'Ma tran Scatter cho bo du lieu trees',pch = 19, col = 'darkgreen')




# Nap du lieu va xu ly gia tri NA cho airquality
data(airquality)
aq <- na.omit(airquality) # Loai bo cac dong co gia tri NA [3]
# Chon cac bien can thiet cho nhom C
du_lieu_C <- aq[, c('Ozone', 'Temp', 'Wind', 'Solar.R')]
# Ve ma tran Scatter plot
pairs(du_lieu_C, main = 'Ma tran Scatter cho bo du lieu airquality', pch = 19, col = 'orange')
```

# Bài 2: Hồi quy tuyến tính đơn
```
# 1. Nap du lieu cars
data(cars)
# 2. Xay dung mo hinh hoi quy don: dist la bien phu thuoc (Y), speed la bien doc lap (X)
mo_hinh_A <- lm(dist ~ speed, data = cars)
# 3. Xem ket qua chi tiet cua mo hinh
summary(mo_hinh_A)




# 1. Nap du lieu trees 
data(trees)
# 2. Xay dung mo hinh hoi quy don: Volume ~ Girth
mo_hinh_B <- lm(Volume ~ Girth, data = trees)
# 3. Xem ket qua
summary(mo_hinh_B)




# 1. Nap du lieu va xu ly gia tri NA cho airquality
data(airquality)
aq <- na.omit(airquality) # Loai bo cac dong co gia tri NA [3]
# 2. Xay dung mo hinh hoi quy don: Ozone ~ Temp
mo_hinh_C <- lm(Ozone ~ Temp, data = aq)
# 3. Xem ket qua
summary(mo_hinh_C)
```

# Bài 3: Hồi quy tuyến tính bội và dự báo
```
# 1. Nap du lieu cars
data(cars)
# 2. Xay dung mo hinh hoi quy don: dist la bien phu thuoc (Y), speed la bien doc lap (X)
mo_hinh_A <- lm(dist ~ speed, data = cars)
# 3. Xem ket qua chi tiet cua mo hinh
summary(mo_hinh_A)
# 4. Tao du lieu moi de du bao
xe_moi_A <- data.frame(speed = c(20, 30))
# 5. Du bao voi khoang tin cay 95% (su dung mo hinh hoi quy don da tao o Bai 2)
du_bao_A <- predict(mo_hinh_A, newdata = xe_moi_A, interval = 'prediction', level = 0.95)
print(du_bao_A)
# 6. Xay dung mo hinh bac 2
mo_hinh_A_mo_rong <- lm(dist ~ speed + I(speed^2), data = cars)
# 7. So sanh R-squared hieu chinh (adj.r.squared) de xem mo hinh nao tot hon
summary(mo_hinh_A)$adj.r.squared
summary(mo_hinh_A_mo_rong)$adj.r.squared




# 1. Nap du lieu trees 
data(trees)
# 2. Xay dung mo hinh hoi quy don: Volume ~ Girth
mo_hinh_B <- lm(Volume ~ Girth, data = trees)
# 3. Xem ket qua
summary(mo_hinh_B)
# 4. Xay dung mo hinh 2 bien doc lap
mo_hinh_B_boi <- lm(Volume ~ Girth + Height, data = trees)
summary(mo_hinh_B_boi) # Xem he so b_Height va danh gia R2 hieu chinh
cay_moi_B <- data.frame(Girth = 14, Height = 76)
du_bao_B <- predict(mo_hinh_B_boi, newdata = cay_moi_B, interval = 'prediction', level = 0.95)
print(du_bao_B)




# 1. Nap du lieu va xu ly gia tri NA cho airquality
data(airquality)
aq <- na.omit(airquality) # Loai bo cac dong co gia tri NA [3]
# 2. Xay dung mo hinh hoi quy don: Ozone ~ Temp
mo_hinh_C <- lm(Ozone ~ Temp, data = aq)
# 3. Xem ket qua
summary(mo_hinh_C)
# 4. Mo hinh 2 bien: Temp va Wind
mo_hinh_C_2bien <- lm(Ozone ~ Temp + Wind, data = du_lieu_C)
# 5. Mo hinh 3 bien: Temp, Wind va Solar.R
mo_hinh_C_3bien <- lm(Ozone ~ Temp + Wind + Solar.R, data = du_lieu_C)
# 6. So sanh de chon mo hinh tot nhat (dua tren R2 hieu chinh cao nhat)
summary(mo_hinh_C_2bien)$adj.r.squared
summary(mo_hinh_C_3bien)$adj.r.squared
# 7. Du bao (Cau 7): Du bao Ozone khi Temp = 85, Wind = 8, Solar.R = 200
ngay_moi_C <- data.frame(Temp = 85, Wind = 8, Solar.R = 200)
du_bao_C <- predict(mo_hinh_C_3bien, newdata = ngay_moi_C, interval = 'prediction', level = 0.95)
print(du_bao_C)
```
