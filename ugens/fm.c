#include "plumber.h"
#include "macros.h"

typedef struct {
    sp_fosc *osc;
    sp_ftbl *ft;
} sporth_fm_d;

int sporth_fm(sporth_stack *stack, void *ud) 
{
    if(stack->error > 0) return PLUMBER_NOTOK;

    plumber_data *pd = ud;
    SPFLOAT out = 0, amp, freq, car, mod, index;
    sporth_fm_d *fm;
    switch(pd->mode){
        case PLUMBER_CREATE:
            printf("creating FM function... \n");
            fm = malloc(sizeof(sporth_fm_d));
            sp_ftbl_create(pd->sp, &fm->ft, 4096);
            sp_fosc_create(&fm->osc);
            plumber_add_module(pd, SPORTH_FM, sizeof(sporth_fm_d), fm);
            break;
        case PLUMBER_INIT:
            if(sporth_check_args(stack, "fffff") != SPORTH_OK) {
                stack->error++;
                return PLUMBER_NOTOK;
            }
            fm = pd->last->ud;

            index = sporth_stack_pop_float(stack);
            mod = sporth_stack_pop_float(stack);
            car = sporth_stack_pop_float(stack);
            amp = sporth_stack_pop_float(stack);
            freq = sporth_stack_pop_float(stack);

            sp_gen_sine(pd->sp, fm->ft);
            sp_fosc_init(pd->sp, fm->osc, fm->ft);
            sporth_stack_push_float(stack, 0.0);
            break;
        case PLUMBER_COMPUTE:
            fm = pd->last->ud;
            if(sporth_check_args(stack, "fffff") != SPORTH_OK) {
                stack->error++;
                return PLUMBER_NOTOK;
            }

            index = sporth_stack_pop_float(stack);
            mod = sporth_stack_pop_float(stack);
            car = sporth_stack_pop_float(stack);
            amp = sporth_stack_pop_float(stack);
            freq = sporth_stack_pop_float(stack);

            fm->osc->freq = freq;
            fm->osc->amp = amp;
            fm->osc->car = car;
            fm->osc->mod = mod;
            fm->osc->indx = index;

            sp_fosc_compute(pd->sp, fm->osc, NULL, &out);
            sporth_stack_push_float(stack, out);
            break;
        case PLUMBER_DESTROY:
            fm = pd->last->ud;
            sp_fosc_destroy(&fm->osc);
            sp_ftbl_destroy(&fm->ft);
            free(fm);
            break;
        default:
            printf("Error: Unknown mode!"); 
            stack->error++;
            return PLUMBER_NOTOK;
            break;
    }   
    return PLUMBER_OK;
}