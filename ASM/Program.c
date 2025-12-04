#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;
int nhapSoNguyen();
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
int isPrime(long long n);
int isPerfectSquare(long long n);

int nhapSoNguyen() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Vui long nhap 1 so nguyen: ");
        // Xóa bộ đệm đầu vào
        while (getchar() != '\n');
    }
    return x;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int isPrime(long long n) {
    if (n <= 1) return 0;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int isPerfectSquare(long long n) {
    if (n < 0) return 0;
    long long root = round(sqrt(n));
    return root * root == n;
}

PhanSo rutGon(PhanSo ps) {
    if (ps.mau == 0) return ps;
    long long ucln = gcd(abs(ps.tu), abs(ps.mau));
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

void xacDinhHocLuc(float diem, char* hocLuc) {
    if (diem >= 9.0) {
        strcpy(hocLuc, "Xuat sac");
    }
    else if (diem >= 8.0) {
        strcpy(hocLuc, "Gioi");
    }
    else if (diem >= 6.5) {
        strcpy(hocLuc, "Kha");
    }
    else if (diem >= 5.0) {
        strcpy(hocLuc, "Trung binh");
    }
    else {
        strcpy(hocLuc, "Yeu");
    }
}

void kiemTraSoNguyen() {
    long long x;
    printf("\n--- CHUC NANG 1: KIEM TRA SO NGUYEN ---\n");
    printf("Nhap vao mot so nguyen x: ");

    if (scanf("%lld", &x) != 1) {
        printf("Loi! Vui long nhap so nguyen.\n");
        while (getchar() != '\n');
        return;
    }

    while (getchar() != '\n');

    printf("Ket qua kiem tra cho so %lld:\n", x);
    printf("  • %lld la so nguyen\n", x);


    if (isPrime(x)) {
        printf("  • %lld la so nguyen to \n", x);
    }
    else {
        printf("  • %lld khong phai la so nguyen to \n", x);
    }

    if (isPerfectSquare(x)) {
        printf("  • %lld la so chinh phuong \n", x);
    }
    else {
        printf("  • %lld khong phai la so chinh phuong \n", x);
    }
}

void timUocVaBoiChung() {
    long long x, y;
    printf("\n--- CHUC NANG 2: TIM UOC SO CHUNG VÀ BOI SO CHUNG ---\n");

    printf("Nhap so nguyen x: ");
    if (scanf("%lld", &x) != 1) {
        printf("Loi nhap!\n");
        while (getchar() != '\n'); return;
    }
    printf("Nhap so nguyen y: ");
    if (scanf("%lld", &y) != 1) {
        printf("Loi nhap!\n");
        while (getchar() != '\n'); return;
    }
    while (getchar() != '\n');

    long long abs_x = llabs(x);
    long long abs_y = llabs(y);

    if (abs_x == 0 && abs_y == 0) {
        printf("Uoc chung lon nhat khong xac đinh, Boi chung nho nhat là 0.\n");
        return;
    }

    long long ucln = gcd(abs_x, abs_y);
    long long bcnn = lcm(abs_x, abs_y);

    printf("Ket qua cho 2 so (%lld, %lld):\n", x, y);
    printf("  • Uoc so chung lon nhat cua 2 so: %lld\n", ucln);
    printf("  • Boi so chung nho nhat của 2 so: %lld\n", bcnn);
}

void tinhTienKaraoke() {
    int gioBatDau, gioKetThuc;
    const int GIA_3_GIO_DAU = 150000;
    const double GIA_GIO_DAU_LE = GIA_3_GIO_DAU / 3.0;

    printf("\n--- CHUC NANG 3: TINH TIEN KẨOKE ---\n");
    printf("Quan hoat dong tu 12h-23h.\n");

    printf("Nhap gio bat dau (12-23): ");
    gioBatDau = nhapSoNguyen();
    printf("Nhap gio ket thuc (12-23): ");
    gioKetThuc = nhapSoNguyen();
    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Loi: (Nhap gio bat dau tu 12h, gio ket thuc den 23h.)\n");
        return;
    }

    int tongSoGio = gioKetThuc - gioBatDau;
    double tongTien = 0.0;

    if (tongSoGio <= 3) {
        tongTien = tongSoGio * GIA_GIO_DAU_LE;
    }
    else {

        tongTien += GIA_3_GIO_DAU;
     
        int soGioGiamGia = tongSoGio - 3;
        double giaGiamGia = GIA_GIO_DAU_LE * (1.0 - 0.30); 
        tongTien += soGioGiamGia * giaGiamGia;
    }

    double phanTramGiamThem = 0.0;
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        phanTramGiamThem = 0.10;
        double soTienGiamThem = tongTien * phanTramGiamThem;
        tongTien -= soTienGiamThem;
        printf("Áp dụng giảm giá giờ vàng (14h-17h): %.0f VND (10%%)\n", soTienGiamThem);
    }

    printf("Chi tiết:\n");
    printf("  • Giờ bắt đầu: %d, Giờ kết thúc: %d\n", gioBatDau, gioKetThuc);
    printf("  • Tổng số giờ: %d giờ\n", tongSoGio);
    printf("  • Tổng tiền (chưa giảm thêm): %.0f VND\n", (gioBatDau >= 14 && gioBatDau <= 17) ? tongTien / (1.0 - phanTramGiamThem) : tongTien);
    printf("  • Giá tiền cần thanh toán sau khi áp dụng tất cả giảm giá: %.0f VND\n", tongTien);
}

void tinhTienDien() {
    double kwh;
    double tongTien = 0.0;
    double bac1_gia = 1678.0;
    double bac2_gia = 1734.0;
    double bac3_gia = 2014.0;
    double bac4_gia = 2536.0;
    double bac5_gia = 2834.0;
    double bac6_gia = 2927.0;

    printf("\n--- CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN ---\n");
    printf("Nhập số kWh điện sử dụng: ");
    if (scanf("%lf", &kwh) != 1 || kwh < 0) {
        printf("Lỗi nhập liệu! Vui lòng nhập số kWh hợp lệ.\n");
        while (getchar() != '\n'); return;
    }
    while (getchar() != '\n');

    double luongConLai = kwh;

    printf("Chi tiết tính toán:\n");
    if (luongConLai > 400) {
        double soDienBac6 = luongConLai - 400;
        double tienBac6 = soDienBac6 * bac6_gia;
        tongTien += tienBac6;
        luongConLai = 400;
        printf("  • Bậc 6 (Trên 400 kWh): %.0f kWh * %.0f đ/kWh = %.0f đ\n", soDienBac6, bac6_gia, tienBac6);
    }

    if (luongConLai > 300) {
        double soDienBac5 = luongConLai - 300;
        double tienBac5 = soDienBac5 * bac5_gia;
        tongTien += tienBac5;
        luongConLai = 300;
        printf("  • Bậc 5 (301-400 kWh): %.0f kWh * %.0f đ/kWh = %.0f đ\n", soDienBac5, bac5_gia, tienBac5);
    }

    if (luongConLai > 200) {
        double soDienBac4 = luongConLai - 200;
        double tienBac4 = soDienBac4 * bac4_gia;
        tongTien += tienBac4;
        luongConLai = 200;
        printf("  • Bậc 4 (201-300 kWh): %.0f kWh * %.0f đ/kWh = %.0f đ\n", soDienBac4, bac4_gia, tienBac4);
    }

    if (luongConLai > 100) {
        double soDienBac3 = luongConLai - 100;
        double tienBac3 = soDienBac3 * bac3_gia;
        tongTien += tienBac3;
        luongConLai = 100;
        printf("  • Bậc 3 (101-200 kWh): %.0f kWh * %.0f đ/kWh = %.0f đ\n", soDienBac3, bac3_gia, tienBac3);
    }

    if (luongConLai > 50) {
        double soDienBac2 = luongConLai - 50;
        double tienBac2 = soDienBac2 * bac2_gia;
        tongTien += tienBac2;
        luongConLai = 50;
        printf("  • Bậc 2 (51-100 kWh): %.0f kWh * %.0f đ/kWh = %.0f đ\n", soDienBac2, bac2_gia, tienBac2);
    }

    if (luongConLai > 0) {
        double soDienBac1 = luongConLai;
        double tienBac1 = soDienBac1 * bac1_gia;
        tongTien += tienBac1;
        printf("  • Bậc 1 (0-50 kWh): %.0f kWh * %.0f đ/kWh = %.0f đ\n", soDienBac1, bac1_gia, tienBac1);
    }

    printf("\nSố tiền cần phải trả (chưa bao gồm VAT): %.0f VND\n", tongTien);
}

void chucNangDoiTien() {
    int soTien;
    int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int soLuong[9] = { 0 }; 

    printf("\n--- CHỨC NĂNG 5: CHỨC NĂNG ĐỔI TIỀN ---\n");
    printf("Nhập vào số tiền cần đổi (VNĐ, chỉ chấp nhận số nguyên dương): ");
    soTien = nhapSoNguyen();

    if (soTien <= 0) {
        printf("Số tiền không hợp lệ. Vui lòng nhập số tiền dương.\n");
        return;
    }

    int tienConLai = soTien;

    printf("Kết quả đổi tiền cho %d VNĐ:\n", soTien);

    for (int i = 0; i < 9; i++) {
        soLuong[i] = tienConLai / menhGia[i];
        tienConLai %= menhGia[i];
        if (soLuong[i] > 0) {
            printf("  • %d tờ mệnh giá %d VNĐ\n", soLuong[i], menhGia[i]);
        }
    }
}

void tinhLaiXuatVay() {
    double tienVay;
    const double LAI_SUAT_THANG = 0.05;
    const int KY_HAN = 12;

    printf("\n--- CHỨC NĂNG 6: TÍNH LÃI SUẤT VAY TRẢ GÓP ---\n");
    printf("  • Lãi suất cố định: 5%%/tháng\n");
    printf("  • Kỳ hạn: 12 tháng\n");
    printf("Nhập số tiền muốn vay (VNĐ, ví dụ: 12000000): ");
    if (scanf("%lf", &tienVay) != 1 || tienVay <= 0) {
        printf("Lỗi nhập liệu! Vui lòng nhập số tiền hợp lệ.\n");
        while (getchar() != '\n'); return;
    }
    while (getchar() != '\n');

    printf("\nBảng chi tiết trả nợ trong 12 tháng (Theo phương thức dư nợ giảm dần):\n");
    printf("+-------+-----------+---------+-----------+-----------+\n");
    printf("| Tháng | Tiền Gốc | Lãi (5%%)| Tổng Trả | Dư Nợ Còn |\n");
    printf("+-------+-----------+---------+-----------+-----------+\n");

    double gocHangThang = tienVay / KY_HAN;
    double duNoConLai = tienVay;
    double tongTienTra = 0.0;
    double tongLai = 0.0;

    for (int i = 1; i <= KY_HAN; i++) {
        double laiThang = duNoConLai * LAI_SUAT_THANG;
        double tongTraThang = gocHangThang + laiThang;
        duNoConLai -= gocHangThang;

        tongTienTra += tongTraThang;
        tongLai += laiThang;

        printf("| %5d | %9.0f | %7.0f | %9.0f | %9.0f |\n",
            i, gocHangThang, laiThang, tongTraThang, (i == KY_HAN) ? 0.0 : duNoConLai);
    }
    printf("+-------+-----------+---------+-----------+-----------+\n");
    printf("  • Tổng tiền lãi phải trả: %.0f VNĐ\n", tongLai);
    printf("  • Tổng tiền phải trả (Gốc + Lãi): %.0f VNĐ\n", tongTienTra);
}

void tinhVayTienMuaXe() {
    int phanTramVayToiDa;
    const double GIA_TRI_XE_VAY_CO_DINH = 500000000.0;
    const int THOI_HAN_NAM = 24;
    const int THOI_HAN_THANG = THOI_HAN_NAM * 12;
    const double LAI_SUAT_NAM = 0.072;
    const double LAI_SUAT_THANG = LAI_SUAT_NAM / 12.0;

    printf("\n--- CHỨC NĂNG 7: CHƯƠNG TRÌNH VAY TIỀN MUA XE ---\n");
    printf("  • Số tiền vay cố định: %.0f VNĐ\n", GIA_TRI_XE_VAY_CO_DINH);
    printf("  • Thời hạn vay: %d năm (%d tháng)\n", THOI_HAN_NAM, THOI_HAN_THANG);
    printf("  • Lãi suất cố định năm: %.1f%%\n", LAI_SUAT_NAM * 100);

    printf("Nhập số phần trăm vay tối đa (ví dụ: 80 - Trả trước 20%%): ");
    phanTramVayToiDa = nhapSoNguyen();

    if (phanTramVayToiDa <= 0 || phanTramVayToiDa > 100) {
        printf("Phần trăm vay không hợp lệ. Phải nằm trong khoảng (1 - 100).\n");
        return;
    }

    double phanTramTraTruoc = (100.0 - phanTramVayToiDa) / 100.0;
    double tienTraTruoc = GIA_TRI_XE_VAY_CO_DINH * phanTramTraTruoc;

    double P = GIA_TRI_XE_VAY_CO_DINH;
    double i = LAI_SUAT_THANG;
    int n = THOI_HAN_THANG;

    double tuSo = i * pow(1 + i, n);
    double mauSo = pow(1 + i, n) - 1;
    double tienTraGopHangThang = P * (tuSo / mauSo);

    printf("\n--- KẾT QUẢ TÍNH TOÁN ---\n");
    printf("  • Phần trăm vay: %d%%\n", phanTramVayToiDa);
    printf("  • Phần trăm trả trước: %.0f%%\n", 100.0 - phanTramVayToiDa);
    printf("  • Số tiền phải trả lần đầu (Trả trước): %.0f VNĐ\n", tienTraTruoc);
    printf("  • Số tiền phải trả hàng tháng (Trả góp): %.0f VNĐ\n", tienTraGopHangThang);
    printf("  • Tổng số tiền gốc và lãi phải trả sau %d năm: %.0f VNĐ\n", THOI_HAN_NAM, tienTraGopHangThang * n);
}

void gameFPOLY() {
    printf("\n--- CHỨC NĂNG 9: GAME FPOLY-LOTT (2/15) ---\n");
    printf("Bạn sẽ chọn 2 số (từ 1 đến 15).\n");
    srand(time(NULL));
    int soNgauNhien1 = (rand() % 15) + 1;
    int soNgauNhien2;
    do {
        soNgauNhien2 = (rand() % 15) + 1;
    } while (soNgauNhien2 == soNgauNhien1);

    int soNguoiDung1, soNguoiDung2;
    printf("Nhập số thứ nhất (1-15): ");
    soNguoiDung1 = nhapSoNguyen();
    printf("Nhập số thứ hai (1-15, khác số thứ nhất): ");
    soNguoiDung2 = nhapSoNguyen();

    if (soNguoiDung1 < 1 || soNguoiDung1 > 15 || soNguoiDung2 < 1 || soNguoiDung2 > 15 || soNguoiDung1 == soNguoiDung2) {
        printf("Lỗi: Số nhập vào không hợp lệ (phải từ 1-15 và khác nhau).\n");
        return;
    }

    int soLanTrung = 0;

    if (soNguoiDung1 == soNgauNhien1 || soNguoiDung1 == soNgauNhien2) {
        soLanTrung++;
    }

    if (soNguoiDung2 == soNgauNhien1 || soNguoiDung2 == soNgauNhien2) {
        soLanTrung++;
    }

    printf("\n--- KẾT QUẢ XỔ SỐ ---\n");
    printf("  • Số của bạn: %d và %d\n", soNguoiDung1, soNguoiDung2);
    printf("  • Số trúng thưởng: %d và %d\n", soNgauNhien1, soNgauNhien2);
    printf("  • Số lần trùng khớp: %d\n", soLanTrung);

    switch (soLanTrung) {
    case 0:
        printf("  -> Chúc bạn may mắn lần sau!\n");
        break;
    case 1:
        printf("  -> Chúc mừng bạn đã trúng giải nhì!\n");
        break;
    case 2:
        printf("  -> CHÚC MỪNG BẠN ĐÃ TRÚNG GIẢI NHẤT!\n");
        break;
    default:
        break;
    }
}

void tinhToanPhanSo() {
    PhanSo ps1, ps2;
    printf("\n--- CHỨC NĂNG 10: CHƯƠNG TRÌNH TÍNH TOÁN PHÂN SỐ ---\n");

    printf("Nhập tử số phân số 1: ");
    ps1.tu = nhapSoNguyen();
    printf("Nhập mẫu số phân số 1 (khác 0): ");
    ps1.mau = nhapSoNguyen();
    while (ps1.mau == 0) {
        printf("Mẫu số phải khác 0. Nhập lại: ");
        ps1.mau = nhapSoNguyen();
    }
    ps1 = rutGon(ps1);
    printf("Phân số 1 đã rút gọn: %d/%d\n", ps1.tu, ps1.mau);

    printf("\nNhập tử số phân số 2: ");
    ps2.tu = nhapSoNguyen();
    printf("Nhập mẫu số phân số 2 (khác 0): ");
    ps2.mau = nhapSoNguyen();
    while (ps2.mau == 0) {
        printf("Mẫu số phải khác 0. Nhập lại: ");
        ps2.mau = nhapSoNguyen();
    }
    ps2 = rutGon(ps2);
    printf("Phân số 2 đã rút gọn: %d/%d\n", ps2.tu, ps2.mau);


    PhanSo ketQua;
    int a, b, c, d;
    a = ps1.tu; b = ps1.mau;
    c = ps2.tu; d = ps2.mau;

    printf("\n--- KẾT QUẢ TÍNH TOÁN ---\n");

    ketQua.tu = a * d + c * b;
    ketQua.mau = b * d;
    ketQua = rutGon(ketQua);
    printf("  • Tổng (%d/%d + %d/%d) = %d/%d\n", a, b, c, d, ketQua.tu, ketQua.mau);

    ketQua.tu = a * d - c * b;
    ketQua.mau = b * d;
    ketQua = rutGon(ketQua);
    printf("  • Hiệu (%d/%d - %d/%d) = %d/%d\n", a, b, c, d, ketQua.tu, ketQua.mau);

    ketQua.tu = a * c;
    ketQua.mau = b * d;
    ketQua = rutGon(ketQua);
    printf("  • Tích (%d/%d * %d/%d) = %d/%d\n", a, b, c, d, ketQua.tu, ketQua.mau);

    if (c == 0) {
        printf("  • Thương: KHÔNG THỂ CHIA (Phân số thứ hai bằng 0).\n");
    }
    else {
        ketQua.tu = a * d;
        ketQua.mau = b * c;
        ketQua = rutGon(ketQua);
        printf("  • Thương (%d/%d / %d/%d) = %d/%d\n", a, b, c, d, ketQua.tu, ketQua.mau);
    }
}

void hienThiMenu() {
    printf("|              MENU           |\n");
    printf("1. KIEM TRA SO NGUYEN                               \n");
    printf("2. TIM UOC CHUNG LON NHAT VA BOI CHUNG NHO NHAT     \n");
    printf("3. TINH TIEN QUAN KARAOKE                           \n");
    printf("4. TINH TIEN DIEN                                   \n");
    printf("5. DOI TIEN THEO MENH GIA NHO NHAT                  \n");
    printf("6. TINH LAI XUAT VAY NGAN HANG                      \n");
    printf("7. VAY TIEN MUA XE                                  \n");
    printf("8. SAP XEP THONG TIN SINH VIEN                      \n");
    printf("9. GAME FPOLY_LOTT                                 \n");
    printf("10. TINH TOAN PHAN SO                              \n");
    printf("VUI LONG CHON CHUC NANG (0-10): ");
}

int main() {
    int luaChon;
    do {
        hienThiMenu();
        if (scanf("%d", &luaChon) != 1) {
            printf("\nLua chon cua ban khong hop le, vui long nhap tu 1 den 10.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n');

        switch (luaChon) {
        case 1:
            kiemTraSoNguyen();
            break;
        case 2:
            timUocVaBoiChung();
            break;
        case 3:
            tinhTienKaraoke();
            break;
        case 4:
            tinhTienDien();
            break;
        case 5:
            chucNangDoiTien();
            break;
        case 6:
            tinhLaiXuatVay();
            break;
        case 7:
            tinhVayTienMuaXe();
            break;
        case 9:
            gameFPOLY();
            break;
        case 10:
            tinhToanPhanSo();
            break;
        default:
            printf("\nChuc nang chua ton tai, ban hay nhap chuc nang 1 den 10.\n");
        }

        if (luaChon != 0) {
            printf("\nNhan ENTER de quay lai Menu.");
            while (getchar() != '\n');
        }

    } while (luaChon != 0);
    return 0;
}