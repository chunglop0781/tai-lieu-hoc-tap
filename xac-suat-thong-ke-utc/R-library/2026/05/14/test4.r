# Co mau cho uoc luong trung binh
# n >= (z_{a/2} sigma / E)^2
# Dung s cua mau hien co lam uoc tinh sigma
E_mu <- 0.1       # Sai so cho phep
conf_mu <- 0.95
z_mu <- qnorm (1 -(1-conf_mu)/2)
sigma_uc <- s     # Dung s de uoc tinh sigma
n_min_mu <- (z_mu * sigma_uc / E_mu)^2
n_min_mu <- ceiling (n_min_mu)
# Lam tron len (luon luon lam tron len!)
cat('=== Co mau toi thieu uoc luong trung binh ===\n')
cat('Sai so cho phep E =', E_mu, '\n')
cat('Muc tin cay =', conf_mu*100, '%\n')
cat('z_{alpha/2} =', round(z_mu,4), '\n')
cat('Uoc tinh sigma =', round(sigma_uc,4), '\n')
cat ('Co mau toi thieu =', n_min_mu, 'sinh vien\n')
# Phan tich do nhay: E thay doi thi n thay doi the nao?
E_vals <- seq(0.05, 0.25, by = 0.05)
n_vals <- ceiling ((z_mu * sigma_uc / E_vals)^2)
data.frame(E = E_vals, n_toi_thieu = n_vals)
E_p2 <- 0.08 # Sai so cho phep
conf_p <- 0.95
z_p2 <- qnorm(1-(1-conf_p)/2)
# Truong hop A: Da co uoc tinh p_hat tu nghien cuu truoc
p_uoc <- p_hat
# Dung phat da tinh o Phan 3
n_min_A <- ceiling ((z_p2/E_p2)^2 * p_uoc * (1-p_uoc))
# Truong hop B: Chua co uoc tinh -> dung p = 0.5 (an toan nhat)
n_min_B <- ceiling ((z_p2/E_p2)^2 * 0.5 * 0.5)
cat('=== Co mau toi thieu uoc luong ti le ===\n')
cat ('Sai so E', E_p2, '| Muc TC', conf_p*100, '%\n\n')
cat('TH A (co p_hat =', round (p_uoc, 2), '): n >=', n_min_A, '\n')
cat('TH B ( p = 0.5 an toan) n >=', n_min_B, '\n')
cat('\n-> Chon n', max (n_min_A, n_min_B), '(lay gia tri lon hon)\n')