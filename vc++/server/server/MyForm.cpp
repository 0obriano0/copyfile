#include "MyForm.h"

using namespace server;

[STAThreadAttribute]

int main(array<System::String ^> ^args) {
	omp_set_nested(1);//���}openmp �_������� �ѦҸ�� https://www.phototalks.idv.tw/academic/?p=1997 

	//true == 1, false == 0
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �إߥD�����ð���
	Application::Run(gcnew MyForm());

	//�����{������A�æ^�� 0 �N��{�����楿�`�L�����C
	return 0;
}