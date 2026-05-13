# --- Cach 1: Nhap truc tiep bang vector gia tri va tan so ---
diem <- c(5, 6, 7, 8, 9, 10) # Gia tri
tan_so <- c(2, 5, 10, 12, 7, 4) # Tan so tuong ung
du_lieu1 <- data.frame(diem = diem, tan_so = tan_so)
# Khai bao bang tan so
bang_ts <- data.frame (Diem = diem, TanSo = tan_so)
print (bang_ts)
# Tinh cac chi so thong ke tu bang tan so
tong_f <- sum (tan_so)                            # N = 40
trung_binh <- sum(diem * tan_so) / tong_f         # Mean
cat('Trung binh:', round (trung_binh, 2), '\n')
# Vi du 1: Lam tron so don le
# trung_binh <- 10.56789
# result <- round(trung_binh, 2)
# Ket qua: 10.57
# Vi du 2: Lam tron mot vector/cot du lieu
# data <- c(1.234, 5.678, 9.101)
# round(data, 2)
# Ket qua: 1.23 5.68 9.10
# ---Cach 2: Mo rong thanh du lieu tho (rep) ---
# Dung rep() de tao lai tung gia tri theo tan so
diem_raw <<- rep (diem, times = tan_so)
# diem (x): Vector cac gia tri can lap lai.
# tan_so (times): So lan lap lai.
cat('Du lieu tho:', diem_raw, '\n')
cat('Kiem tra:', length (diem_raw), 'quan sat\n')
# Sau khi co du lieu tho, dung binh thuong nhu phan truoc
mean (diem_raw)
median (diem_raw)
sd (diem_raw)
summary (diem_raw)

# ---Du lieu lien tuc: bang phan phoi theo lop ---
# Gia su co bang: [155,160), [160,165), [165,170), [170,175), [175,185)
gio_tren <- c(160, 165, 170, 175, 185)
# Can tren lop
gio_duoi <- c(155, 160, 165, 170, 175)
# Can duoi lop
tan_so2 <- c(2, 4, 5, 3, 1)
du_lieu2 <- data.frame(gio_tren = gio_tren, gio_duoi = gio_duoi, tan_so2 = tan_so2)
# Tan so
# Diem giua lop (dai dien cho tinh toan)
diem_giua <- (gio_duoi + gio_tren) / 2
cat('Diem giua:', diem_giua, '\n')
# Uoc tinh trung binh va do lech chuan tu bang tan so lop
N <- sum (tan_so2)
tb_uoc <- sum (diem_giua * tan_so2) / N
sd_uoc <- sqrt(sum (tan_so2 * (diem_giua - tb_uoc)^2) / (N -1))
cat('Trung binh uoc tinh:', round(tb_uoc, 2), 'cm\n')
cat('Do lech chuan uoc tinh:', round (sd_uoc, 2), 'cm\n')
# Ve histogram tu bang tan so (dung barplot)
nhan_lop <- paste0 ('[', gio_duoi, ',', gio_tren, ')')
barplot (tan_so2,
         names.arg = nhan_lop,
         main = 'Phan phoi tan so Chieu cao',
         xlab = 'Lop chieu cao (cm)',
         ylab = 'Tan so',
         col = 'steelblue', border = 'white')
# Kiem tra du lieu thieu
sum(is.na(du_lieu1))
colSums(is.na(du_lieu1))
# Tom tat nhanh summary (du lieu)
# Kiem tra kieu du lieu tung bien
sapply (du_lieu1, class)
#Tong so gia tri NA
#NA theo tung cot
sum(is.na(du_lieu2))
colSums(is.na(du_lieu2))
sapply (du_lieu2, class)
# is.na() dung de kiem tra gia tri bi thieu (missing value)
# NA (Not Available)
