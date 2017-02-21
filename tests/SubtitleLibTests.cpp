#include <QTest>
#include <QDebug>
#include <QString>

#include <src/ParseHelper.h>
#include <src/SubtitleTime.h>
#include <src/Subtitle.h>

using namespace sub_util;

class SubtitleLibTests : public QObject
{
	Q_OBJECT
private slots:
	void init()
	{
		 m_subtitleTestData = QFINDTESTDATA("testData/subtitle.srt");
		 QVERIFY2(!m_subtitleTestData.isEmpty(), "Cannot to find test data");
	}

	void test_Time()
	{
		auto defaultTime = SubtitleTime();
		QCOMPARE(defaultTime.hour(),   0);
		QCOMPARE(defaultTime.minute(), 0);
		QCOMPARE(defaultTime.second(), 0);
		QCOMPARE(defaultTime.msec(),   0);

		auto time1 = SubtitleTime(1, 1, 1, 1);
		QCOMPARE(time1.hour(),   1);
		QCOMPARE(time1.minute(), 1);
		QCOMPARE(time1.second(), 1);
		QCOMPARE(time1.msec(),   1);

		QVERIFY(SubtitleTime(1, 0, 10) < SubtitleTime(1, 1, 1));
	}

	void test_Subtitle()
	{
		auto subtitle = Subtitle(m_subtitleTestData.toStdString());
		QCOMPARE(subtitle.size(), static_cast<size_t>(32));

		QCOMPARE(subtitle[4].start(), SubtitleTime(0, 0, 57, 746));
		QCOMPARE(subtitle[4].end(),   SubtitleTime(0, 0, 59, 113));
		QCOMPARE(subtitle[4].text(), std::string("Wait, does he eat chalk?"));
	}

	void test_ParseHelper()
	{
		std::string timeString = "9:00:51,383 --> 10:00:52,625 00:00:55,453  fdfsadfs 00:15:55,99";
		auto times = parseTimes(timeString);
		QCOMPARE(times.size(), static_cast<size_t>(4));
		QCOMPARE(times[0], SubtitleTime( 9,  0, 51, 383));
		QCOMPARE(times[1], SubtitleTime(10,  0, 52, 625));
		QCOMPARE(times[2], SubtitleTime( 0,  0, 55, 453));
		QCOMPARE(times[3], SubtitleTime( 0, 15, 55,  99));
	}

private:
	QString m_subtitleTestData;
};

QTEST_MAIN(SubtitleLibTests)

#include "SubtitleLibTests.moc"
