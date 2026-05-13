# Tao du lieu mau
du_lieu <- data.frame(
  GioiTinh = c('Nu', 'Nam', 'Nu', 'Nam', 'Nu', 'Nam', 'Nam', 'Nam', 'Nu', 'Nam', 'Nam', 'Nu', 'Nam', 'Nu', 'Nam'),
  Nganh = c('KT', 'CNTT', 'KT', 'CNTT', 'KH', 'KT', 'CNTT', 'KH','KH', 'CNTT', 'KT','KH','CNTT', 'KT', 'CNTT'),
  ChieuCao = c(165, 172, 158, 180, 168, 175, 170, 182, 163, 174, 177, 160, 185, 167, 173),
  CanNang = c(55, 68, 50, 80, 62, 72, 65, 85, 52, 70, 75, 53, 90, 60, 71))
# Chuyen bien phan loai sang factor
du_lieu$GioiTinh <- factor (du_lieu$GioiTinh, levels = c('Nam', 'Nu'))
du_lieu$Nganh <- factor (du_lieu$Nganh)
# Kiem tra lai
levels(du_lieu$GioiTinh)
nlevels(du_lieu$Nganh)
# Them mot so gia tri NA gia lap
set.seed (42)
# set.seed(42) trong R la mot lenh dung de co dinh ket qua cua cac ham tao so ngau nhien
# Vi du:
# set.seed(42)
# runif(3) # Ket qua lan 1
# [1] 0.9148060 0.9370754 0.2861395
# set.seed(42)
# runif(3) # Ket qua lan 2 (giong y het lan 1)
# [1] 0.9148060 0.9370754 0.2861395
du_lieu_na <- du_lieu
du_lieu_na$CanNang [sample (1:nrow (du_lieu_na), 2)] <- NA
# sample(1:nrow(du_lieu_na), 2) trong R duoc su dung de chon ngau nhien 2 chi so dong (index) tu khung du lieu (data frame) co ten la du_lieu_na
# Phuong phap 1: Loai bo hang co NA
du_sach1 <- na.omit(du_lieu_na)
# Su dung na.omit() de xoa dong co NA
# Ket qua: Chi giu lai cac dong khong co NA
# Phuong phap 2: Thay bang gia tri trung binh
du_sach2 <- du_lieu_na
du_sach2$CanNang[is.na(du_sach2$CanNang)] <- mean (du_lieu_na$CanNang, na.rm = TRUE)
cat ('Ban goc:', nrow (du_lieu_na), 'hang\n')
cat ('Sau na.omit:', nrow (du_sach1), 'hang\n')
# Phat hien outlier bang IQR
detect_outlier <- function (x) {
  # detect_outlier: phat hien ngoai le
  # na.rm: "NA remove" (loai bo gia tri thieu)
  Q1 <- quantile (x, 0.25, na.rm = TRUE)
  Q3 <- quantile (x, 0.75, na.rm = TRUE)
  # quantile() la mot ham duoc su dung de tinh toan cac phan vi mau (sample quantiles)
  IQR <- Q3 -Q1
  x < (Q1 - 1.5 * IQR) | x > (Q3 + 1.5 * IQR)
}
# Kiem tra tung bien so
cat ('Outlier ChieuCao:', sum (detect_outlier (du_lieu$ChieuCao)), '\n')
cat ('Outlier CanNang: ', sum(detect_outlier(du_lieu$CanNang)), '\n')
# Xem hang co outlier
du_lieu [detect_outlier (du_lieu$CanNang), ]
# Tinh BMI
du_lieu$BMI <- du_lieu$CanNang / (du_lieu$ChieuCao/100)^2
du_lieu$BMI <- round (du_lieu$BMI, 1)
#Phan loai BMI
du_lieu$PhanLoaiBMI <- cut (du_lieu$BMI,
      breaks = c(0, 18.5, 24.9, 29.9, Inf),
      labels = c('Thieu can', 'Binh thuong', 'Thua can', 'Beo phi'), right = TRUE)
# Kiem tra ket qua
table (du_lieu$PhanLoaiBMI)

