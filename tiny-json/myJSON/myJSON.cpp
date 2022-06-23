#include "myJSON.h"
#include <cassert>
#include <math.h>
#include <cstdio>

namespace ben {

	#ifndef PARSE_STACK_INIT_SIZE
	#define PARSE_STACK_INIT_SIZE 256
	#endif

	typedef struct { //Ϊ�˱��ڽ������ݣ���������ṹ������
		const char* json;
		char* stack;
		size_t size;
		size_t top;
		
	}context;


	//��ȡstring����ĸ������������ľͲ鿴��һ��
	void expect(context* c, char ch) { 
		do
		{
			assert(*c->json == ch);
			c->json++;
		} while (0);
	}

	bool isDigit029(char ch) {
		return (ch >= '0' && ch <= '9');
	}

	bool isDigit129(char ch) {
		return (ch >= '1' && ch <= '9');
	}



	void prase_init(json_value* v) {
		do {
			v->type = M_TEXT_NULL;
		} while (0);
	}

	void set_null(json_value* v) { //?
		json_free(v);
	}

	static void* context_push(context* c, size_t size) {
		void* ret;
		assert(size > 0);
		if (c->top + size >= c->size) {
			if (c->size == 0)
				c->size = PARSE_STACK_INIT_SIZE;
			while (c->top + size >= c->size)
				c->size += c->size >> 1;  /* c->size * 1.5 ��������� */ 
			c->stack = (char*)realloc(c->stack, c->size);
		}
		ret = c->stack + c->top;
		c->top += size;
		return ret;
	}

	void putc(context* c, char ch) {
		do {
			/*char* temp;
			temp = (char*)context_push(c, sizeof(char));
			*temp = ch;*/
			*(char*)context_push(c, sizeof(char)) = (ch);

		} while (0);
	}

//#define putc(c, ch) do { *(char*)context_push(c, sizeof(char)) = (ch); } while(0)

	static void *context_pop(context* c, size_t size) {//void��������,pop��size��С������
		assert(c->top >= size);
		return c->stack + (c->top -= size);
	}
	
	static int parse_value(context* c, json_value* v);//ǰ������

	static void parse_whitespace(context* c) {
		const char* p = c->json;
		while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
			p++;
		c->json = p;
	}

	static int parse_literal(context* c, json_value* v, const char* literal, json_type type) {
		size_t i;
		expect(c, literal[0]);
		for (i = 0; literal[i + 1]; i++)
			if (c->json[i] != literal[i + 1])
				return PARSE_INVALID_VALUE;
		c->json += i;
		v->type = type;
		return PARSE_OK;
	}

	static int parse_number(context* c, json_value* v) {
		const char* p = c->json;
		//���ſ�ͷ
		if (*p == '-') p++;
		//����0
		if (*p == '0') {
			p++;
			printf("%s\n", p);
			if(( * p != '.') && ( * p != NULL)) return PARSE_ROOT_NOT_SINGULAR;
		}
		else {
			printf("%s\n", p);
			if (!isDigit129(*p)) return PARSE_INVALID_VALUE;
			p++;
			while (isDigit029(*p)) {
				p++;
			}
		}
		if (*p == '.') {
			p++;
			if (!isDigit029(*p)) return PARSE_INVALID_VALUE;
			p++;
			while (isDigit029(*p)) {
				p++;
			}
		}
		if (*p == 'e' || *p == 'E') {
			p++;
			if (*p == '+' || *p == '-') p++;
			if (!isDigit029(*p)) return PARSE_INVALID_VALUE;
			p++;
			while (isDigit029(*p)) {
				p++;
			}
		}
		errno = 0;
		v->num = strtod(c->json, NULL);
		if (errno == ERANGE && (v->num == HUGE_VAL || v->num == -HUGE_VAL)) return PARSE_TO_BIG_NUMBER;
		v->type = M_NUMBER;
		c->json = p;
		return PARSE_OK;
	}

	const char* parse_hex4(const char* p, unsigned* u) {
		int i;
		*u = 0;
		for (i = 0; i < 4; i++) {
			char ch = *p++;
			*u <<= 4; //����4λ��1111 1111 1111 1111
			if (ch >= '0' && ch <= '9')  *u |= ch - '0';
			else if (ch >= 'A' && ch <= 'F')  *u |= ch - ('A' - 10);
			else if (ch >= 'a' && ch <= 'f')  *u |= ch - ('a' - 10);
			else return NULL; //�����ʽ���� ���� 4��16��������
		}
		return p;
	}

	 // ��㷶Χ	         ���λ��	�ֽ�1	 �ֽ�2	    �ֽ�3	      �ֽ�4
	//	U + 0000 ~U + 007F	    7	0xxxxxxx
	//	U + 0080 ~U + 07FF	    11	110xxxxx	10xxxxxx
	//	U + 0800 ~U + FFFF	    16	1110xxxx	10xxxxxx	10xxxxxx
	//	U + 10000 ~U + 10FFFF	21	11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
	static void encode_utf8(context* c, unsigned u) {
		if (u <= 0x7F) { //127 7λ
			putc(c, u & 0xFF); //255 8λ ��λ&
		}
		else if (u <= 0x7FF) { // 111 1111 1111,11λ
			putc(c, 0xC0 | ((u >> 6) & 0xFF));
			putc(c, 0x80 | (u & 0x3F));
		}
		else if (u <= 0xFFFF) {
			putc(c, 0xE0 | ((u >> 12) & 0xFF));
			putc(c, 0x80 | ((u >> 6) & 0x3F));
			putc(c, 0x80 | (u & 0x3F));
		}
		else {
			assert(u <= 0x10FFFF);
			putc(c, 0xF0 | ((u >> 18) & 0xFF));
			putc(c, 0x80 | ((u >> 12) & 0x3F));
			putc(c, 0x80 | ((u >> 6) & 0x3F));
			putc(c, 0x80 | (u & 0x3F));
		}
	}

	int STRING_ERROR(context* c,int ret,size_t head) {
		do { 
			c->top = head; 
			return ret; 
		} while (0);
	}

	static int parse_array(context* c, json_value* v) {
		int size = 0;
		int ret;
		expect(c, '[');
		parse_whitespace(c);
		if (*c->json == ']') {//����������
			c->json++;
			v->type = M_ARRAY;
			v->size = 0;
			v->arr = NULL;
			return PARSE_OK;
		}
		for (;;) {
			json_value temp;
			prase_init(&temp);
			if ((ret = parse_value(c, &temp)) != PARSE_OK) { //����
				printf("array �� ���޷�����������\n");
				break;
			}
			memcpy(context_push(c, sizeof(json_value)), &temp, sizeof(json_value));
			//context_push ���ص���һ����ջ��ѹ���������еĳ�Ա
			//��temp json_valueѹ�뵽�����ջ����ȥ��
			size++;
			//array = %x5B ws [ value *( ws %x2C ws value ) ] ws %x5D
			//[[1,2],[3,4],"abc"]
			//ע�⣬������һ���ݹ���ã�parse_array������parse_value����parse_value��Ҳ�е���parse_array
			//����parse_value���õĽ�������value���浽temp���棬Ȼ���temp�浽c����ȥ��
			// ע�������ǰ�json value���͵����ݣ�memcpy����void���͵�context_push�ķ���ֵ��ȥ�ˣ�ʵ������char*���������ﱻת��void*�����ˣ�
			//void *memcpy(void *str1, const void *str2, size_t n)
			//str1 -- ָ�����ڴ洢�������ݵ�Ŀ�����飬����ǿ��ת��Ϊ void* ָ�롣
			//str2 -- ָ��Ҫ���Ƶ�����Դ������ǿ��ת��Ϊ void* ָ�롣
			//n -- Ҫ�����Ƶ��ֽ�����
			parse_whitespace(c);
			//%x2C�Ƕ��ţ����  ws %x2C ws value 
			if (*c->json == ',') {
				c->json++;
				parse_whitespace(c);
			}
			else if (*c->json == ']') {//������
				c->json++;
				v->type = M_ARRAY;
				v->size = size;
				cout << "arr_size:" << v->size << endl;
				size = sizeof(json_value) * size;
				memcpy(v->arr = (json_value*)malloc(size), context_pop(c, size), size);
				return PARSE_OK;
			}
			else {
				ret = PARSE_MISS_COMMA_OR_SQUARE_BRACKET;
				break;
			}
		}
		cout << "�����У�size�ǣ�" << size << endl;
		for (int i = 0; i < size; i++) {
			json_free((json_value*)context_pop(c,sizeof(json_value))); //����֮��͵ð�context pop������Ķ���ɾ�ɾ�
			//�����������ָ��
		}
		v->type = M_ARRAY;
		return ret;
	}

	static int parse_string(context* c, json_value* v) {
		size_t head = c->top;
		size_t len;
		unsigned u,u2;
		const char* p;
		expect(c, '\"');
		p = c->json;
		for (;;) {
			char ch = *p++;
			//cout << "��ӡһ��ch:  " << *p << endl;
			printf("��ӡһ��*p��%s \n", c->json);
			switch (ch) {
			case '\"':
				len = c->top - head;
				set_string(v, (const char*)context_pop(c, len), len);
				c->json = p;
				return PARSE_OK;
			case '\\':
				switch (*p++) {
				case 'u':
					if (!(p = parse_hex4(p, &u))) {
						return PARSE_INVALID_UNICODE_HEX;
						//STRING_ERROR(c, PARSE_INVALID_UNICODE_HEX, head);
						break;
					}
					if (u >= 0xD800 && u <= 0xDBFF) { /* surrogate pair */
						if (*p++ != '\\')
							return PARSE_INVALID_UNICODE_SURROGATE;
							//STRING_ERROR(c, PARSE_INVALID_UNICODE_SURROGATE, head);
						if (*p++ != 'u')
							return PARSE_INVALID_UNICODE_SURROGATE;
							//STRING_ERROR(c, PARSE_INVALID_UNICODE_SURROGATE, head);
						if (!(p = parse_hex4(p, &u2)))
							return PARSE_INVALID_UNICODE_HEX;
							//STRING_ERROR(c, PARSE_INVALID_UNICODE_HEX, head);
						if (u2 < 0xDC00 || u2 > 0xDFFF)
							return PARSE_INVALID_UNICODE_SURROGATE;
							//STRING_ERROR(c, PARSE_INVALID_UNICODE_SURROGATE, head);
						u = (((u - 0xD800) << 10) | (u2 - 0xDC00)) + 0x10000;
					}
					encode_utf8(c, u);
					break;
				case '\"': putc(c, '\"'); break;
				case '\\': putc(c, '\\'); break;
				case '/':  putc(c, '/'); break;
				case 'b':  putc(c, '\b'); break;
				case 'f':  putc(c, '\f'); break;
				case 'n':  putc(c, '\n'); break;
				case 'r':  putc(c, '\r'); break;
				case 't':  putc(c, '\t'); break;
				default:
					c->top = head;
					return PARSE_INVALID_STRING_ESCAPE;
				}
				break;
			case '\0':
				c->top = head;
				return PARSE_MISS_QUATATION_MARK;
			default:
				if ((unsigned char)ch < 0x20) {
					c->top = head;
					return PARSE_INVALID_STRING_CHAR;
				}
				putc(c, ch);
			}
		}
	}


	static int parse_value(context* c, json_value* v) { 
		switch (*c->json) {
		case 't':  return parse_literal(c, v,"true",M_TEXT_TRUE);
		case 'f':  return parse_literal(c, v, "false", M_TEXT_FALSE);
		case 'n':  return parse_literal(c, v, "null", M_TEXT_NULL);
		case '\0': return PARSE_EXPECT_VALUE;
		case '"':  return parse_string(c, v);
		case '[': return parse_array(c, v);
		default:   return parse_number(c,v);
		}
	}

	int parse(json_value* v, const char* json) {
		context c;
		int ret;
		assert(v != NULL);
		c.json = json;
		c.stack = NULL;
		c.size = c.top = 0;
		prase_init(v);
		parse_whitespace(&c);
		if ((ret = parse_value(&c, v)) == PARSE_OK) {
			parse_whitespace(&c);
			if (*c.json != '\0') {
				v->type = M_TEXT_NULL;
				ret = PARSE_ROOT_NOT_SINGULAR;
			}
		}
		assert(c.top == 0);
		free(c.stack);
		return ret;
	}

	void json_free(json_value* v) {
		assert(v != NULL);
		switch (v->type) {
		case M_STRING:
			free(v->str.s);
			break;
		case M_ARRAY:
			for (int i = 0; i < v->size; i++) {
				json_free(&v->arr[i]);
			}
			free(v->arr);
			break;
		default: break;
		}
		v->type = M_TEXT_NULL;
	}


	json_type get_type(const json_value* v) {
		assert(v != NULL);
		cout <<"000000000000000000" << v->type << endl;
		return v->type;
	}

	int get_boolean(const json_value* v) {
		assert(v != NULL && (v->type == M_TEXT_TRUE || v->type == M_TEXT_FALSE));
		return v->type == M_TEXT_TRUE;
	}

	void set_boolean(json_value* v, int b) {
		json_free(v);
		v->type = b ? M_TEXT_TRUE : M_TEXT_FALSE;
	}

	double get_number(const json_value* v) {
		assert(v != NULL && v->type == M_NUMBER);
		return v->num;
	}
	
	void set_number(json_value* v, double n) {
		json_free(v);
		v->num = n;
		v->type = M_NUMBER;
	}

	const char* get_string(const json_value* v) {
		assert(v != NULL && v->type == M_STRING);
		return v->str.s;
	}


	size_t get_string_len(const json_value* v) {

		assert(v != NULL && v->type == M_STRING);
		return v->str.len;
	}
	void set_string(json_value* v, const char* s, size_t len) {
		printf("��ӡ %s \n", s);
		assert(v != NULL && (s!=NULL || len == 0));
		json_free(v);
		v->str.s = (char*)malloc(len + 1);
		memcpy(v->str.s, s, len); //����
		v->str.s[len] = '\0';
		v->str.len = len;
		v->type =  M_STRING;
	}

	size_t get_array_size(const json_value* v) {
		assert(v != NULL && v->type ==	M_ARRAY);
		cout << "size:???::: " << v->size << endl;
		return v->size;
	}
	json_value* get_array_element(const json_value* v, size_t index) {
		assert(v != NULL && v->type == M_ARRAY);
		cout << index << " " << v->size << endl;
		assert(index < v->size);
		return &v->arr[index];
	}
}