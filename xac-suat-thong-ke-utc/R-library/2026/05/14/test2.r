# --- Cach 1: Tinh tay bang R ---
alpha <- 0.05
z <- qnorm (1 - alpha/2)
E <- z * s/sqrt(n)
# = 1.96
# Bien do sai so
lower_z <- x_bar - E
upper_z <- x_bar + E
cat('\n=== Khoang tin cay 95% cho GPA trung binh (phuong phap Z) ===\n')
cat('x_bar=', round(x_bar, 4), '\n')
cat('z_alpha2=', round (z, 4), '\n')
cat('Bien do sai so E', round (E, 4), '\n')
cat ('Khoang tin cay: [', round (lower_z,4), ';', round (upper_z,4), ']\n')
# lower_z: gioi han duoi (lower bound)
# upper_z: gioi han tren (upper bound)
# --- Cach 2: Dung t.test() (n lon -> ket qua gan nhu z) ---
  ket_qua <- t.test(sv$GPA, conf.level = 0.95)
print(ket_qua)
#Lay mau nho n = 12
set.seed(7)
mau_nho <- sv$GPA [sample (1:50, 12)]
# Lay ngau nhien 12 so tu 1 den 50, khong lap lai
# sample(x, n): {x = tap gia tri can lay || n = so phan tu lay ngau nhien}
n2 <- length (mau_nho)
xb2 <- mean (mau_nho)
s2 <- sd (mau_nho)
# --- Cach 1: Tinh tay ---
alpha2 <- 0.05
t_cv <- qt (1 -  alpha2/2, df = n2 -1) # gia tri toi han t
E2 <- t_cv * s2 / sqrt (n2)
cat('\n=== Khoang tin cay 95% (phuong phap t, n = 12 ) ===\n')
cat('n =', n2, '| x_bar =', round (xb2,4), '| s =', round(s2,4), '\n')
cat('t_{alpha/2, df = 11} =' , round (t_cv, 4), '\n')
cat('E =', round (E2, 4), '\n')
cat ('Khoang tin cay: [', round(xb2-E2,4), ';', round(xb2+E2,4), ']\n')
# ---- Cach 2: t.test() ----
t.test (mau_nho, conf.level = 0.95)
# Tinh KTC voi 3 muc tin cay khac nhau
muc_tin_cay <- c(0.90, 0.95, 0.99)
cat ('\n=== So sanh KTC o cac muc tin cay (n = 50) ===\n')
cat (sprintf('%-12s %-10s %-10s %-10s %-10s\n', 'Muc TC', 'z a/2', 'Bien do E', 'Can duoi', 'Can tren'))
for (conf in muc_tin_cay) {
z_val <- qnorm (1 - (1-conf)/2)
E_val <- z_val * s / sqrt(n)
cat (sprintf('%-12s %-10.4f %-10.4f %-10.4f %-10.4f\n',
          paste0(conf*100, '%'), z_val, E_val,
          x_bar - E_val, x_bar + E_val))
}
# Ve truc quan do rong KTC
plot (NULL, xlim=c(2.4, 3.4), ylim=c(0.5, 3.5),
     main='Khoang tin cay o cac muc tin cay khac nhau',
    xlab='GPA', ylab='', yaxt='n')
nhan <- c('90%', '95%', '99%')
mau <- c('#27ae60','#2980b9','#e74c3c')
for (i in seq_along (muc_tin_cay)) {
  z_i <- qnorm(1-(1-muc_tin_cay[i])/2)
  E_i <- z_i * s / sqrt(n)
  segments (x_bar-E_i, i, x_bar+E_i, i, col=mau[i], lwd=4)
  points (x_bar, i, pch=19, col='black', cex=1.2)
  text (x_bar-E_i-0.03, i, nhan[i], adj=1, font=2, col=mau[i])
}
abline (v=x_bar, lty = 2 , col='gray50')
