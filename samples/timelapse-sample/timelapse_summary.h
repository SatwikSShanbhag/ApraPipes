
#include <PipeLine.h>
#include <CudaMemCopy.h>
#include "CudaStreamSynchronize.h"
#include <Mp4ReaderSource.h>
#include <MotionVectorExtractor.h>
#include <ColorConversionXForm.h>

class TimelapsePipeline {
public:
  TimelapsePipeline();
  bool setupPipeline(const std::string &videoPath,
                     const std::string &outFolderPath);
  bool startPipeline();
  bool stopPipeline();

private:
  PipeLine timelapseSamplePipeline;
  cudastream_sp mCudaStream_;
  apracucontext_sp mCuContext;
  framemetadata_sp mH264ImageMetadata;
  boost::shared_ptr<Mp4ReaderSource> mMp4Reader;
  boost::shared_ptr<MotionVectorExtractor> mMotionExtractor;
  boost::shared_ptr<ColorConversion> mColorchange1;
  boost::shared_ptr<ColorConversion> mColorchange2;
  boost::shared_ptr<Module> mSync;
  boost::shared_ptr<Module> mEncoder;
  boost::shared_ptr<Module> mMp4WriterSink;
  boost::shared_ptr<Module> mCopy;
};