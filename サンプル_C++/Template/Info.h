#pragma once

/*�I�y���[�^�̍ő吔*/
#define OP_MAX 4

/*������*/
enum class STATE {
	/*��~*/
	stop,
	/*���s*/
	execute
};

/*�G���x���[�v�̓�����*/
enum class EV_STATE {
	/*�J�n*/
	start,
	/*�A�^�b�N*/
	attack,
	/*�f�B�P�C*/
	decay,
	/*�T�X�e�B��*/
	sustain,
	/*�m�[�g�I�t*/
	note_off,
	/*�����[�X*/
	release,
};

/*�I�y���[�^�̎��g���^�C�v*/
enum class TYPE {
	/*�䗦�\��*/
	variable,
	/*�Œ�\��*/
	fix
};
