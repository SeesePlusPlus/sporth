/* This is a generated header file */
#ifdef MINIMAL
#include <stdlib.h>
#endif

enum {
SPORTH_FLOAT,
SPORTH_STRING,
SPORTH_IGNORE,
SPORTH_FUNC,
SPORTH_NOTOK,
SPORTH_OK,
SPORTH_WORD
};

#define SPORTH_FOFFSET 2
#define SPORTH_MAXCHAR 200
#define SPORTH_STACK_SIZE 32

typedef struct {
    float fval;
    char *sval;
    int type;
} sporth_stack_val;

typedef struct {
    int pos;
    uint32_t error;
    sporth_stack_val stack[SPORTH_STACK_SIZE];
} sporth_stack;

typedef struct sporth_entry {
    uint32_t val;
    char *key;
    struct sporth_entry *next;
} sporth_entry;

typedef struct {
    uint32_t count;
    sporth_entry root;
    sporth_entry *last;
} sporth_list ;

typedef struct {
    sporth_list list[256];
} sporth_htable;

typedef struct {
    const char *name;
    int (*func)(sporth_stack *, void *);
    void *ud;
} sporth_func;

typedef struct sporth_data {
    sporth_htable dict;
    uint32_t nfunc;
    sporth_func *flist;
    sporth_stack stack;
} sporth_data;

uint32_t sporth_hash(const char *str);
int sporth_search(sporth_htable *ht, const char *key, uint32_t *val);
int sporth_htable_add(sporth_htable *ht, const char *key, uint32_t val);
int sporth_htable_init(sporth_htable *ht);
int sporth_htable_destroy(sporth_htable *ht);

int sporth_stack_init(sporth_stack *stack);
int sporth_stack_push_float(sporth_stack *stack, float val);
int sporth_stack_push_string(sporth_stack *stack, char **str);
float sporth_stack_pop_float(sporth_stack *stack);
const char * sporth_stack_pop_string(sporth_stack *stack);
int sporth_check_args(sporth_stack *stack, const char *args);
int sporth_register_func(sporth_data *sporth, sporth_func *flist);
int sporth_exec(sporth_data *sporth, const char *keyword);
int sporth_init(sporth_data *sporth);
int sporth_destroy(sporth_data *sporth);
int sporth_stack_pos(sporth_stack *stack);

int sporth_gettype(sporth_data *sporth, char *str, int mode);
int sporth_parse(sporth_data *sporth, const char *filename);
char * sporth_tokenizer(const char *str,
        uint32_t size, uint32_t *pos);
int sporth_lexer(char *str, int32_t size);
sporth_stack_val * sporth_stack_get_last(sporth_stack *stack);

size_t sporth_getline(char **lineptr, size_t *n, FILE *stream);

void sporth_print(sporth_data *sporth, const char *fmt, ...);
enum {
SP_DUMMY = SPORTH_FOFFSET - 1,
SPORTH_MUL,
SPORTH_ADD,
SPORTH_SUB,
SPORTH_DIV,
SPORTH_MARKLEFT,
SPORTH_MARKRIGHT,
SPORTH_AND,
SPORTH_OR,
SPORTH_XOR,
SPORTH_LEFTSHIFT,
SPORTH_RIGHTSHIFT,
SPORTH_MOD,
SPORTH_ABS,
SPORTH_ADSR,
SPORTH_ALLPASS,
SPORTH_ATONE,
SPORTH_AUTOWAH,
SPORTH_ADDv2,
SPORTH_AMPDB,
SPORTH_BAL,
SPORTH_BISCALE,
SPORTH_BITCRUSH,
SPORTH_BLSAW,
SPORTH_BLSQUARE,
SPORTH_BLTRIANGLE,
SPORTH_BPM2DUR,
SPORTH_BPM2RATE,
SPORTH_BRANCH,
SPORTH_BROWN,
SPORTH_BUTBP,
SPORTH_BUTBR,
SPORTH_BUTHP,
SPORTH_BUTLP,
SPORTH_CDB,
SPORTH_CDBLOAD,
SPORTH_CDBTAB,
SPORTH_CF,
SPORTH_CHANGED,
SPORTH_CLIP,
SPORTH_CLOCK,
SPORTH_COMB,
SPORTH_CONV,
SPORTH_COUNT,
SPORTH_CROSSFADE,
SPORTH_DCBLK,
SPORTH_DELAY,
SPORTH_DIODE,
SPORTH_DISKIN,
SPORTH_DIST,
SPORTH_DIVv2,
SPORTH_DMETRO,
SPORTH_DRIP,
SPORTH_DROP,
SPORTH_DTRIG,
SPORTH_DUP,
SPORTH_DUP2,
SPORTH_DUR,
SPORTH_DURS,
SPORTH_DUST,
SPORTH_EDO,
SPORTH_EQ,
SPORTH_EQFIL,
SPORTH_EVAL,
SPORTH_EXPON,
SPORTH_F,
SPORTH_FLOAD,
SPORTH_FLOADI,
SPORTH_FCLOSE,
SPORTH_FEXEC,
SPORTH_FLOOR,
SPORTH_FM,
SPORTH_FOF,
SPORTH_FOFILT,
SPORTH_FOG,
SPORTH_FOSC,
SPORTH_FRAC,
SPORTH_FTSUM,
SPORTH_GBUZZ,
SPORTH_GEN_EVAL,
SPORTH_GEN_FILE,
SPORTH_GEN_LINE,
SPORTH_GEN_PADSYNTH,
SPORTH_GEN_SINE,
SPORTH_GEN_RAND,
SPORTH_GEN_COMPOSITE,
SPORTH_GEN_SINESUM,
SPORTH_GEN_SPORTH,
SPORTH_GEN_VALS,
SPORTH_GET,
SPORTH_GT,
SPORTH_HILBERT,
SPORTH_IN,
SPORTH_INCR,
SPORTH_INV,
SPORTH_JCREV,
SPORTH_JITTER,
SPORTH_LIMIT,
SPORTH_LINE,
SPORTH_LOAD,
SPORTH_SDELAY,
SPORTH_SLICE,
SPORTH_SLIST,
SPORTH_SQRT,
SPORTH_LOADFILE,
SPORTH_LOADSPA,
SPORTH_LOG,
SPORTH_LOG10,
SPORTH_LPC,
SPORTH_LPCSYNTH,
SPORTH_LPF18,
SPORTH_LSYS,
SPORTH_LT,
SPORTH_MAX,
SPORTH_MAYGATE,
SPORTH_MAYTRIG,
SPORTH_METRO,
SPORTH_MINCER,
SPORTH_MIN,
SPORTH_MIX,
SPORTH_MODE,
SPORTH_MOOGLADDER,
SPORTH_MTOF,
SPORTH_MULv2,
SPORTH_NE,
SPORTH_NOISE,
SPORTH_NSMP,
SPORTH_OSC,
SPORTH_OSCMORPH4,
SPORTH_OSCMORPH2,
SPORTH_P,
SPORTH_PALIAS,
SPORTH_PAN,
SPORTH_PANST,
SPORTH_PAREQ,
SPORTH_PAULSTRETCH,
SPORTH_PDHALF,
SPORTH_PEAKLIM,
SPORTH_PHASER,
SPORTH_PHASOR,
SPORTH_PINKNOISE,
SPORTH_PLUCK,
SPORTH_PORT,
SPORTH_POS,
SPORTH_POSC3,
SPORTH_PRINT,
SPORTH_PROP,
SPORTH_POLYSPORTH,
SPORTH_PSET,
SPORTH_PSH,
SPORTH_PSHIFT,
SPORTH_PST,
SPORTH_PTRACK,
SPORTH_RAND,
SPORTH_RANDH,
SPORTH_RANDI,
SPORTH_REF,
SPORTH_RENDER,
SPORTH_RESON,
SPORTH_REVERSE,
SPORTH_REVSC,
SPORTH_RMS,
SPORTH_ROT,
SPORTH_ROUND,
SPORTH_RPT,
SPORTH_RSPLINE,
SPORTH_SAMPHOLD,
SPORTH_SATURATOR,
SPORTH_SAW,
SPORTH_SAY,
SPORTH_SCALE,
SPORTH_SCRAMBLER,
SPORTH_SET,
SPORTH_SETDURS,
SPORTH_SGET,
SPORTH_SINE,
SPORTH_SMOOTHDELAY,
SPORTH_SLICK,
SPORTH_SPA,
SPORTH_SPAREC,
SPORTH_SQUARE,
SPORTH_SR,
SPORTH_SRAND,
SPORTH_SUBv2,
SPORTH_STRESON,
SPORTH_SWAP,
SPORTH_SWITCH,
SPORTH_TABREAD,
SPORTH_TADSR,
SPORTH_TALIAS,
SPORTH_TALKBOX,
SPORTH_TBLDUR,
SPORTH_TBLREC,
SPORTH_TBLSIZE,
SPORTH_TDIV,
SPORTH_TENV,
SPORTH_TENV2,
SPORTH_TENVX,
SPORTH_TGATE,
SPORTH_TGET,
SPORTH_THRESH,
SPORTH_TIMER,
SPORTH_TIN,
SPORTH_TICK,
SPORTH_TOG,
SPORTH_TONE,
SPORTH_TPHASOR,
SPORTH_TPORT,
SPORTH_TPROP,
SPORTH_TRAND,
SPORTH_TRIANGLE,
SPORTH_TRI,
SPORTH_TSEQ,
SPORTH_TSEG,
SPORTH_TSET,
SPORTH_VAR,
SPORTH_VARSET,
SPORTH_VDELAY,
SPORTH_VOC,
SPORTH_VOCODER,
SPORTH_WAVESET,
SPORTH_WRITECODE,
SPORTH_WPKORG35,
SPORTH_ZEROS,
SPORTH_ZITAREV,
SPORTH_ZREV,
SPORTH_LAST
};

#ifndef PLUMBER_H
#define PLUMBER_H

/* it just so happens that PLUMBER_OK and SPORTH_OK are the same values */
enum {
PLUMBER_CREATE,
PLUMBER_INIT,
PLUMBER_COMPUTE,
PLUMBER_DESTROY,
PLUMBER_NOTOK,
PLUMBER_OK,
PLUMBER_PANIC
};

enum {
PTYPE_NIL,
PTYPE_TABLE,
PTYPE_USERDATA
};

typedef int (* plumber_func) (sporth_stack *, void *) ;

typedef struct plumber_ftbl {
    void *ud;
    char *name;
    char to_delete;
    char type;
    struct plumber_ftbl *next;
} plumber_ftbl;

typedef struct {
    uint32_t nftbl;
    plumber_ftbl root;
    plumber_ftbl *last;
} plumber_ftentry;

typedef struct plumber_pipe {
    uint32_t type;
    size_t size;
    void *ud;
    struct plumber_pipe *next;
} plumber_pipe;

typedef struct {
    plumber_func fun;
    void *ud;
} sporth_func_d;

typedef struct {
    uint32_t npipes;
    int tick;
    plumber_pipe root;
    plumber_pipe *last;
} plumbing;

typedef struct plumber_data {
    int mode;
    uint32_t seed;
    sp_data *sp;
    FILE *fp;
    char *filename;
    sporth_data sporth;
    plumbing *pipes;
    /* for add_module function */
    plumbing *tmp;
    int current_pipe;
    plumbing main, alt;

    plumber_ftentry ft1[256];
    plumber_ftentry ft2[256];
    plumber_ftentry *ftmap;
    plumber_ftentry *ftnew, *ftold;
    char delete_ft;

    SPFLOAT p[16];
    void *ud;
    plumber_pipe *next;
    plumber_pipe *last;
    sp_progress *prog;
    int showprog;
    int recompile;
    int stacksize;
    char *str;

    FILE *log;
} plumber_data;

typedef int (* plumber_dyn_func) (plumber_data *, sporth_stack *, void **);

/* needed for dynamic loading */
typedef struct {
    sporth_func_d *fd;
    plumber_dyn_func fun;
    plumber_dyn_func (*getter)(void);
    int (*getter_multi)(int, plumber_dyn_func *);
    const char *filename;
    const char *name;
    void *handle;
    void *ud;
} sporth_fload_d;

#ifdef LIVE_CODING
#include <pthread.h>
typedef struct {
    plumber_data *pd;
    int start;
    pthread_t thread;
    int portno;
} sporth_listener;
void sporth_start_listener(sporth_listener *sl);
#endif

typedef struct {
    unsigned short type;
    void *ud;
} plumber_ptr;

int plumber_init(plumber_data *plumb);
int plumber_register(plumber_data *plumb);
int plumber_clean(plumber_data *plumb);

int plumber_add_float(plumber_data *plumb, plumbing *pipes, float num);
char * plumber_add_string(plumber_data *plumb, plumbing *pipes, const char *str);
int plumber_add_ugen(plumber_data *plumb, uint32_t id, void *ud);

int plumber_compute(plumber_data *plumb, int mode);

int plumber_parse(plumber_data *plumb);
int plumber_parse_string(plumber_data *plumb, const char *str);

int plumber_recompile(plumber_data *plumb);
int plumber_recompile_string(plumber_data *plumb, char *str);
plumbing *plumbing_choose(plumber_data *plumb,
        plumbing *main, plumbing *alt, int *current_pipe);
int plumber_reinit(plumber_data *plumb);
int plumber_reparse(plumber_data *plumb);
int plumber_reparse_string(plumber_data *plumb, char *str);
int plumber_recompile_string(plumber_data *plumb, char *str);
int plumber_recompile_string_v2(plumber_data *plumb,
        char *str,
        void *ud,
        int (*callback)(plumber_data *, void *));
int plumber_recompile_v2(plumber_data *plumb,
        void *ud,
        int (*callback)(plumber_data *, void *));
int plumber_swap(plumber_data *plumb, int error);
int plumber_open_file(plumber_data *plumb, const char *filename);
int plumber_close_file(plumber_data *plumb);

int plumber_gettype(plumber_data *plumb, char *str, int mode);
void plumber_show_pipes(plumber_data *plumb);
int plumber_error(plumber_data *plumb, const char *str);

int plumber_ftmap_init(plumber_data *plumb);
int plumber_ftmap_add(plumber_data *plumb, const char *str, sp_ftbl *ft);
int plumber_ftmap_add_userdata(plumber_data *plumb, const char *str, void *ud);
int plumber_ftmap_add_function(plumber_data *plumb,
        const char *str, plumber_dyn_func f, void *ud);
int plumber_ftmap_search(plumber_data *plumb, const char *str, sp_ftbl **ft);
int plumber_ftmap_search_userdata(plumber_data *plumb, const char *str, void **ud);
int plumber_ftmap_destroy(plumber_data *plumb);
int plumber_ftmap_delete(plumber_data *plumb, char mode);
void plumber_ftmap_dump(plumber_ftentry *ft);
plumbing * plumber_get_pipes(plumber_data *plumb);
int plumber_search(plumber_data *plumb, const char *str, plumber_ftbl **ft);
int plumber_add(plumber_data *plumb, const char *str, plumber_ftbl **ft);

void sporth_run(plumber_data *pd, int argc, char *argv[],
    void *ud, void (*process)(sp_data *, void *));

int plumber_lexer(plumber_data *plumb, plumbing *pipes, char *out, uint32_t len);

int plumbing_init(plumbing *pipes);
int plumbing_destroy(plumbing *pipes);
int plumbing_add_pipe(plumbing *pipes, plumber_pipe *pipe);
int plumbing_compute(plumber_data *plumb, plumbing *pipes, int mode);
int plumbing_parse(plumber_data *plumb, plumbing *pipes);
int plumbing_parse_string(plumber_data *plumb, plumbing *pipes, const char *str);
void plumbing_show_pipes(plumber_data *plumb, plumbing *pipes);
void plumbing_write_code(plumber_data *plumb, plumbing *pipes, FILE *fp);
void plumber_write_code(plumber_data *plumb, FILE *fp);
int plumber_process_null(sp_data *sp, void *ud, void (*callback)(sp_data *, void *));

int plumber_create_var(plumber_data *pd, const char *name, SPFLOAT **var);

int plumber_get_userdata(plumber_data *plumb, const char *name, plumber_ptr **p);
int polysporth_eval(plumber_ptr *p, const char *str);

void plumber_print(plumber_data *pd, const char *fmt, ...);
int plumber_cdbtab(plumber_data *pd, int fd, const char *key, sp_ftbl **ft);

int plumber_stack_pos(plumber_data *pd);

void plumber_check_stack(plumber_data *pd, int nitems);
#endif
