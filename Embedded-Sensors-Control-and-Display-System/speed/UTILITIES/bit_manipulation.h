
#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_


#define SET_BIT(req_register,req_pin) (req_register |= (1<<req_pin))
#define CLEAR_BIT(req_register,req_pin) (req_register &= ~(1<<req_pin))
#define READ_BIT(req_register,req_pin) ((req_register&(1<<req_pin))>>req_pin)



#endif 