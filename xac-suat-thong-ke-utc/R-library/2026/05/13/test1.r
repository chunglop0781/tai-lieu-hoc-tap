# T???o vector d??? li???u
tuoi <- c(22, 25, 21, 28, 23, 26, 24, 30, 22, 25, 27, 21, 29, 23, 26)
chieu_cao <- c(165, 172, 158, 180, 168, 175, 170, 182, 163, 174, 177, 160, 185, 167, 173)
can_nang <- c(55, 68, 50, 80, 62, 72, 65, 85, 52, 70, 75, 53, 90, 60, 71)
gioi_tinh <- c('Nu', 'Nam', 'Nu', 'Nam', 'Nu', 'Nam', 'Nam', 'Nam', 'Nu', 'Nam', 'Nam', 'Nu', 'Nam', 'N u', 'Nam')
nganh <- c('KT', 'CNTT', 'KT', 'CNTT', 'KH', 'KT', 'CNTT', 'KH','KH', 'CNTT', '????','????','CNTT', 'KT', 'CNTT')

# Gop thanh data frame
sv <- data.frame(Tuoi=tuoi, ChieuCao=chieu_cao, CanNang=can_nang, GioiTinh=gioi_tinh, Nganh=nganh)

#Xem du lieu
View (sv)

head (sv, 5) # Xem 5 dong 


# Tao file CSV mau (chay 1 lan dau)
write.csv(sv, 'sinhvien.csv', row.names = FALSE)
# row.names = TRUE =>
#     Name Age
# 1    A  20
# 2    B  25
# row.names = FALSE =>
# "Name","Age"
# A,20
# B,25

# Doc file CSV
du_lieu <- read.csv('sinhvien.csv', header = TRUE)
# header = TRUE du???c s??? d???ng d??? báo cho R bi???t r???ng dòng d???u tiên c???a t???p d??? li???u ch???a tên c???a các c???t


# Kiem tra co ban

dim(du_lieu)
# So hang x so cot

names(du_lieu)
# Ten cac bien

str(du_lieu)
# Cau truc du lieu

class(du_lieu)
# Data Frame (Khung d??? li???u): ch???a d??? li???u du???c t??? ch???c theo dòng (quan sát - observations) và c???t (bi???n - variables)
# Kieu doi tuong