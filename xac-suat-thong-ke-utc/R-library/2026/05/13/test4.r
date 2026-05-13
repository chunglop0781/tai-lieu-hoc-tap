# Tao du lieu mau
du_lieu <- data.frame(
  GioiTinh = c('Nu', 'Nam', 'Nu', 'Nam', 'Nu', 'Nam', 'Nam', 'Nam', 'Nu', 'Nam', 'Nam', 'Nu', 'Nam', 'Nu', 'Nam'),
  Nganh = c('KT', 'CNTT', 'KT', 'CNTT', 'KH', 'KT', 'CNTT', 'KH','KH', 'CNTT', 'KT','KH','CNTT', 'KT', 'CNTT'),
  ChieuCao = c(165, 172, 158, 180, 168, 175, 170, 182, 163, 174, 177, 160, 185, 167, 173),
  CanNang = c(55, 68, 50, 80, 62, 72, 65, 85, 52, 70, 75, 53, 90, 60, 71),
  Tuoi = c(20, 21, 20, 22, 19, 21, 20, 23, 19, 22, 21, 20, 23, 19, 22))
#---Chi so xu huong trung tam---
mean (du_lieu$ChieuCao)        # Trung binh
median (du_lieu$ChieuCao)      # Trung vi
# Mode (R khong co ham san, viet ham rieng)
mode_val <- function (x) { tab <-table(x); names (tab) [which.max(tab)] }
mode_val (du_lieu$Tuoi)
# --- Chi so phan tan ---
var (du_lieu$ChieuCao)         # Phuong sai
sd (du_lieu$ChieuCao)          # Do lech chuan
range (du_lieu$ChieuCao)       # Min, Max
diff (range (du_lieu$ChieuCao))# Khoang bien thien
# ---Tu phan vi
quantile (du_lieu$ChieuCao, c (0.25, 0.5, 0.75))
IQR(du_lieu$ChieuCao)
# Khoang tu phan vi
# --- Tom tat toan bo --
summary (du_lieu, c('Tuoi', 'ChieuCao', 'CanNang', 'BMI'))
# Trung binh theo gioi tinh
tapply (du_lieu$ChieuCao, du_lieu$GioiTinh, mean)
tapply (du_lieu$CanNang, du_lieu$GioiTinh, mean)
# Dung aggregate (linh hoat hon)
du_lieu$BMI <- du_lieu$CanNang / (du_lieu$ChieuCao/100)^2
aggregate (cbind (ChieuCao, CanNang, BMI) ~ GioiTinh, data = du_lieu, FUN = mean)
# Bang tan suat
table (du_lieu$GioiTinh)
table (du_lieu$Nganh, du_lieu$GioiTinh)   # Bang cheo 2 bien
#
# //Bieu do tan suat (Histogram)//
#
#Mo cua so do thi
par (mfrow = c(1, 2))
# Chia cua so thanh 2 cot
# Histogram chieu cao
hist (du_lieu$ChieuCao,
      main = 'Phân phối Chiều cao',
      xlab = 'Chiều cao (cm)',
      ylab = 'Tần số',
      col = 'steelblue',
      border= 'white',
      breaks = 6)
# Them duong cong mat do
hist (du_lieu$ChieuCao, freq = FALSE, col = 'lightblue',
        main = 'Mat do Chieu cao')
lines (density (du_lieu$ChieuCao), col = 'red', lwd = 2)
par (mfrow = c(1, 1)) # Khoi phuc bo cuc
#
# //Bieu do thanh (Barplot)//
#
# //a) Bieu do thanh don – 1 bien phan loai://
#
#Tan suat theo nganh hoc
tan_suat <-table(du_lieu$Nganh)
barplot (tan_suat, main = 'Số sinh viên theo Ngành',
         xlab = 'Ngành học',
         ylab = 'Số sinh viên',
         col = c('#3498db', '#e74c3c','#2ecc71'),
         ylim = c(0, max (tan_suat) + 2))
# Them nhan so lieu tren moi cot
text (x = barplot (tan_suat, plot = FALSE),
      y = tan_suat + 0.3,
        labels = as.character (tan_suat))
#
# //b) Bieu do thanh ghep (Grouped bar) - 2 bien phan loai, thanh dat canh nhau://
#
# Bang cheo Nganh x GioiTinh
bang_cheo <- table (du_lieu$Nganh, du_lieu$GioiTinh)
print (bang_cheo)
# Ve bieu do thanh ghep (beside = TRUE)
barplot (bang_cheo,
         main = 'So sinh viên theo Nganh và Gioi tinh',
         xlab = 'Gioi tính',
         ylab = 'So sinh vien',
         beside = TRUE,
         # <- key: dat canh nhau, khong chong len
         col = c('#3498db', '#e74c3c','#2ecc71'),
         ylim = c(0, max (bang_cheo) + 2),
         legend.text = rownames(bang_cheo),
         args.legend = list (x = 'topright', bty = 'n'))
#
# //c) Bieu do thanh chong (Stacked bar) - 2 bien phan loai, thanh xep chong len nhau://
#
# Ve bieu do thanh chong (beside = FALSE, mac dinh)
barplot (bang_cheo,
         main = 'Co cau Nganh theo Gioi tinh',
         xlab = 'Gioi tinh',
         ylab = 'So sinh vien',
         beside = FALSE,
         # <- key: xep chong
         col = c('#3498db', '#e74c3c', '#2ecc71'),
         legend.text = rownames (bang_cheo),
         args.legend = list(x = 'topright', bty = 'n'))
# Phien ban ty le phan tram (100% stacked)
bang_pct <- prop.table (bang_cheo, margin = 2) * 100 # margin=2: tinh theo cot
barplot (bang_pct,
         main = 'Ty le % Nganh theo Gioi tinh',
         xlab = 'Gioi tinh',
         ylab = 'Ty le (%)',
         beside = FALSE,
         col = c('#3498db','#e74c3c','#2ecc71'),
         legend.text = rownames (bang_pct),
         args.legend = list(x = 'topright', bty = 'n'))
#
# //3.6. Bieu do phan tan (Scatter Plot)//
#
# Scatter plot chieu cao can nang
  plot (du_lieu$ChieuCao, du_lieu$CanNang,
        main = 'Bieu do phan tan: Chieu cao va Can nang',
        xlab = 'Chieu cao (cm)',
        ylab = 'Can nang (kg)',
        pch = 19,
        col = ifelse (du_lieu$GioiTinh == 'Nam', '#3498db', '#e91e8c'),
        cex = 1.3)
# Them chu giai phan biet gioi tinh
legend('topleft', legend = c('Nam', 'Nữ'),
       col = c('#3498db','#e91e8c'), pch = 19, bty = 'n')
# Them duong trung binh ngang va doc (tham khao)
abline (h = mean (du_lieu$CanNang), col = 'gray50', lty = 2)
abline (v = mean (du_lieu$ChieuCao), col = 'gray50', lty = 2)

