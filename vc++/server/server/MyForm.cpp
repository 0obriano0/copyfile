#include "MyForm.h"

using namespace server;

[STAThreadAttribute]

int main(array<System::String ^> ^args) {
	omp_set_nested(1);//打開openmp 巢狀執行緒 參考資料 https://www.phototalks.idv.tw/academic/?p=1997 

	//true == 1, false == 0
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// 建立主視窗並執行
	Application::Run(gcnew MyForm());

	//結束程式執行，並回傳 0 代表程式執行正常無異狀。
	return 0;
}