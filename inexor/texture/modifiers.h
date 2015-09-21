/// @file Texture modifiers mainly applied on load.

#ifndef INEXOR_TEX_MODIFIERS_H
#define INEXOR_TEX_MODIFIERS_H

#include "inexor/engine/engine.h"
#include "inexor/texture/texture.h"

extern void scaletexture(uchar *src, uint sw, uint sh, uint bpp, uint pitch, uchar *dst, uint dw, uint dh);
extern void resizetexture(int w, int h, bool mipmap, bool canreduce, GLenum target, int compress, int &tw, int &th);
extern void scaleimage(ImageData &s, int w, int h);

extern void texoffset(ImageData &s, int xoffset, int yoffset);
extern void texrotate(ImageData &s, int numrots, int type = TEX_DIFFUSE);
extern void texreorient(ImageData &s, bool flipx, bool flipy, bool swapxy, int type = TEX_DIFFUSE);
extern void texflip(ImageData &s);

extern void texmad(ImageData &s, const vec &mul, const vec &add);
extern void texcolorify(ImageData &s, const vec &color, vec weights);
extern void texcolormask(ImageData &s, const vec &color1, const vec &color2);
extern void texdup(ImageData &s, int srcchan, int dstchan);
extern void texmix(ImageData &s, int c1, int c2, int c3, int c4);
extern void texgrey(ImageData &s);
extern void texpremul(ImageData &s);
extern void texagrad(ImageData &s, float x2, float y2, float x1, float y1);
extern void texnormal(ImageData &s, int emphasis);
extern void texblur(ImageData &s, int n, int r);

extern void forcergbimage(ImageData &s);

extern void blurtexture(int n, int bpp, int w, int h, uchar *dst, const uchar *src, int margin = 0);
extern void blurnormals(int n, int w, int h, bvec *dst, const bvec *src, int margin = 0);

#endif //INEXOR_TEX_MODIFIERS_H