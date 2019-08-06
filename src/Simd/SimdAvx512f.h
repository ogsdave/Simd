/*
* Simd Library (http://ermig1979.github.io/Simd).
*
* Copyright (c) 2011-2019 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef __SimdAvx512f_h__
#define __SimdAvx512f_h__

#include "Simd/SimdDefs.h"

namespace Simd
{
#ifdef SIMD_AVX512F_ENABLE    
    namespace Avx512f
    {
        void Fill32f(float * dst, size_t size, const float * value);

        void Gemm32fNN(size_t M, size_t N, size_t K, const float * alpha, const float * A, size_t lda, const float * B, size_t ldb, const float * beta, float * C, size_t ldc);

        void Gemm32fNT(size_t M, size_t N, size_t K, const float * alpha, const float * A, size_t lda, const float * B, size_t ldb, const float * beta, float * C, size_t ldc);

        void NeuralProductSum(const float * a, const float * b, size_t size, float * sum);

        void NeuralAddVectorMultipliedByValue(const float * src, size_t size, const float * value, float * dst);

        void NeuralAddVector(const float * src, size_t size, float * dst);

        void NeuralAddValue(const float * value, float * dst, size_t size);

        void NeuralSigmoid(const float * src, size_t size, const float * slope, float * dst);

        void NeuralRoughSigmoid(const float * src, size_t size, const float * slope, float * dst);

        void NeuralRoughSigmoid2(const float * src, size_t size, const float * slope, float * dst);

        void NeuralDerivativeSigmoid(const float * src, size_t size, const float * slope, float * dst);

        void NeuralTanh(const float * src, size_t size, const float * slope, float * dst);

        void NeuralRoughTanh(const float * src, size_t size, const float * slope, float * dst);

        void NeuralDerivativeTanh(const float * src, size_t size, const float * slope, float * dst);

        void NeuralRelu(const float * src, size_t size, const float * slope, float * dst);

        void NeuralDerivativeRelu(const float * src, size_t size, const float * slope, float * dst);

        void NeuralPow(const float * src, size_t size, const float * exponent, float * dst);

        void NeuralUpdateWeights(const float * x, size_t size, const float * a, const float * b, float * d, float * w);

        void NeuralAdaptiveGradientUpdate(const float * delta, size_t size, size_t batch, const float * alpha, const float * epsilon, float * gradient, float * weight);

        void NeuralAddConvolution2x2Forward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution3x3Forward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution4x4Forward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution5x5Forward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution2x2Backward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution3x3Backward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution4x4Backward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution5x5Backward(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

        void NeuralAddConvolution2x2Sum(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums);

        void NeuralAddConvolution3x3Sum(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums);

        void NeuralAddConvolution4x4Sum(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums);

        void NeuralAddConvolution5x5Sum(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums);

        void NeuralPooling1x1Max3x3(const float * src, size_t srcStride, size_t width, size_t height, float * dst, size_t dstStride);

        void NeuralPooling2x2Max2x2(const float * src, size_t srcStride, size_t width, size_t height, float * dst, size_t dstStride);

        void NeuralPooling2x2Max3x3(const float * src, size_t srcStride, size_t width, size_t height, float * dst, size_t dstStride);

        void NeuralConvolutionForward(const float * src, size_t srcWidth, size_t srcHeight, size_t srcDepth, const float * weight,
            size_t kernelX, size_t kernelY, size_t padX, size_t padY, size_t strideX, size_t strideY, size_t dilationX, size_t dilationY,
            void * buffer, size_t * size, float * dst, size_t dstWidth, size_t dstHeight, size_t dstDepth, int add);

        void SquaredDifferenceSum32f(const float * a, const float * b, size_t size, float * sum);

        void SquaredDifferenceKahanSum32f(const float * a, const float * b, size_t size, float * sum);

        void SvmSumLinear(const float * x, const float * svs, const float * weights, size_t length, size_t count, float * sum);

        void SynetAddBias(const float * bias, size_t channels, size_t spatial, float * dst, SimdTensorFormatType format);

        void SynetConvertImage(size_t batch, size_t channels, size_t spatial, const float * src, SimdTensorFormatType srcFormat, float * dst, SimdTensorFormatType dstFormat);

        void SynetConvertFilter(size_t output, size_t input, size_t kernel, const float * src, SimdTensorFormatType srcFormat, float * dst, SimdTensorFormatType dstFormat);

        void SynetEltwiseLayerForward(float const * const * src, const float * weight, size_t count, size_t size, SimdSynetEltwiseOperationType type, float * dst);

        void SynetFusedLayerForward0(const float * src, const float * bias, const float * scale, size_t channels, size_t spatial, float * dst, SimdTensorFormatType format);

        void SynetFusedLayerForward1(const float * src, const float * bias0, const float * scale1, const float * bias1, size_t channels, size_t spatial, float * dst, SimdTensorFormatType format);

        void SynetFusedLayerForward2(const float * src, const float * scale, const float * bias, size_t count, size_t size, const float * slope, float * dst, SimdBool trans);

        void SynetFusedLayerForward3(const float * src, const float * bias, const float * scale, size_t count, size_t size, float * dst, SimdBool trans);

        void SynetFusedLayerForward4(const float * src, const float * bias0, const float * scale1, const float * bias1, size_t count, size_t size, float * dst, SimdBool trans);

        void SynetFusedLayerForward8(const float * src0, const float * src1, const float * src2, size_t count, size_t size, float * dst, SimdBool trans);

        void SynetFusedLayerForward9(const float * src0, const float * src1, const float * scale, const float * bias, size_t count0, size_t count1, size_t size, float * dst0, float * dst1, SimdBool trans);

        void SynetInnerProductLayerForward(const float * src, const float * weight, const float * bias, size_t count, size_t size, float * dst);

        void SynetLrnLayerCrossChannels(const float * src, size_t half, size_t count, size_t size, const float * k, float * dst, SimdBool trans);

        void SynetSoftmaxLayerForward(const float * src, size_t outer, size_t size, size_t inner, float * dst);

        void SynetPoolingForwardMax(const float * src, size_t srcC, size_t srcH, size_t srcW, size_t kernelY, size_t kernelX,
            size_t strideY, size_t strideX, size_t padY, size_t padX, float * dst, size_t dstH, size_t dstW, SimdBool trans);

        void SynetPreluLayerForward(const float * src, const float * slope, size_t count, size_t size, float * dst, SimdBool trans);

        void SynetRestrictRange(const float * src, size_t size, const float * lower, const float * upper, float * dst);

        void SynetScaleLayerForward(const float * src, const float * scale, const float * bias, size_t channels, size_t spatial, float * dst, SimdTensorFormatType format);

        void Winograd2x3SetFilter(const float * src, size_t size, float * dst, SimdBool trans);

        void Winograd2x3SetInput(const float * src, size_t srcChannels, size_t srcHeight, size_t srcWidth, float * dst, size_t dstStride, SimdBool pad, SimdBool trans);

        void Winograd2x3SetOutput(const float * src, size_t srcStride, float * dst, size_t dstChannels, size_t dstHeight, size_t dstWidth, SimdBool trans);

        void Winograd3x3SetFilter(const float * src, size_t size, float * dst, SimdBool trans);

        void Winograd3x3SetInput(const float * src, size_t srcChannels, size_t srcHeight, size_t srcWidth, float * dst, size_t dstStride, SimdBool pad, SimdBool trans);

        void Winograd3x3SetOutput(const float * src, size_t srcStride, float * dst, size_t dstChannels, size_t dstHeight, size_t dstWidth, SimdBool trans);

        void Winograd4x3SetFilter(const float * src, size_t size, float * dst, SimdBool trans);

        void Winograd4x3SetInput(const float * src, size_t srcChannels, size_t srcHeight, size_t srcWidth, float * dst, size_t dstStride, SimdBool pad, SimdBool trans);

        void Winograd4x3SetOutput(const float * src, size_t srcStride, float * dst, size_t dstChannels, size_t dstHeight, size_t dstWidth, SimdBool trans);
    }
#endif// SIMD_AVX512F_ENABLE
}
#endif//__SimdAvx512f_h__
