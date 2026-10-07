1. Phân tích bài toán I/O
Nội dung	    Chi tiết
Input	        Số lượng tài khoản N
Input	        user_id: Mã tài khoản
Input	        username: Tên tài khoản
Input	        plan_type: 1-Free, 2-Personal, 3-Family
Input	        days_overdue: Số ngày nợ cước
Input	        active_devices: Số thiết bị đang kết nối
Output	        Danh sách tài khoản sau khi rà soát
Output	        Phí dịch vụ thực thu của từng tài khoản
Output	        Tổng doanh thu thực tế
Output	        Tổng số tài khoản bị hạ cấp

Quy định phí
Mã gói	    Tên gói	    Phí/tháng	Thiết bị tối đa
1	        Free	    0	        1
2	        Personal	120000	    1
3	        Family	    250000	    5

Phí phạt Personal: 30.000 VNĐ cho mỗi thiết bị vượt quá 1 thiết bị.

2. Tư duy xử lý
Điểm quan trọng nhất là phải xử lý hạ cấp trước, sau đó mới kiểm tra phạt thiết bị.

Luồng xử lý:
Nhập N
  
Nhập thông tin từng tài khoản
  
Validation dữ liệu
  
Duyệt từng tài khoản
  
days_overdue >= 3 ?
    Có → plan_type = 1 → phí = 0 → tăng số tài khoản hạ cấp
    Không → giữ nguyên gói
  
Nếu plan_type == 2 và active_devices > 1
   tính phí phạt
  
Tính doanh thu
  
In bảng kết quả

3. Thiết kế Struct
Dùng một struct UserAccount để chứa toàn bộ thông tin của một tài khoản:

struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int actual_fee;
};

Trong đó actual_fee dùng để lưu phí dịch vụ thực thu sau khi xử lý.